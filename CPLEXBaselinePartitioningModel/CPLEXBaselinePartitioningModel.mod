/*********************************************
 * OPL 22.1.1.0 Model
 * Author: Tiago
 * Creation Date: 23 Jan 2023 at 15:51:39
 *********************************************/

int NumTasks = ...;
float Slack = ...;

range Tasks = 1..NumTasks;
string Label[Tasks] = ...;

int HardwareTime[Tasks] = ...;
int SoftwareTime[Tasks] = ...;
float UsageFF[Tasks] = ...;
float UsageLUT[Tasks] = ...;
float UsageBRAM[Tasks] = ...;
float UsageDSP[Tasks] = ...;
int Communication[Tasks][Tasks] = ...;

// No need to bother with this yet
// All tasks in edge detect happen only once
//int CallFrequency[Tasks] = ...;

dvar boolean ToHardware[Tasks];

// Minimize overall execution time (assign 1/0 to ToHardware[i] for task i)
minimize
	sum (i in Tasks) (  
		HardwareTime[i] * ToHardware[i] + 
		SoftwareTime[i] * (1 - ToHardware[i]) 
		//+ sum (j in Tasks) (Communication[i][j] * (ToHardware[i] != ToHardware[j]))
	);

subject to {
  	// resource usage constraints
  	resourceFF: sum (i in Tasks) UsageFF[i] * ToHardware[i] <= Slack;
	resourceLUT: sum (i in Tasks) UsageLUT[i] * ToHardware[i] <= Slack;
	resourceDSP: sum (i in Tasks) UsageDSP[i] * ToHardware[i] <= Slack;
	resourceBRAM: sum (i in Tasks) UsageBRAM[i] * ToHardware[i] <= Slack;
	
	mainTasks: forall (i in Tasks)
				if (Label[i] == "main_begin" || Label[i] == "main_end")
					ToHardware[i] == 0;
}

tuple ToHardwareSolutionT {
	string label;
	string value;
};
{ToHardwareSolutionT} ToHardwareSolution = {<Label[i0], (ToHardware[i0] == 0 ? "SW" : "HW")> | i0 in Tasks};
float ExecTime = sum (i in Tasks) (
					SoftwareTime[i] * (1 - ToHardware[i]) + 
					HardwareTime[i] * ToHardware[i] +
					sum (j in Tasks)
						(ToHardware[i] != ToHardware[j] ? Communication[i][j] : 0)
				);
  
execute {
    writeln("Finished generating a solution using ILP");
  	for (i in ToHardwareSolution) writeln(i);
	writeln("Total solution time (HW/SW partitioning overall execution time): " + ExecTime + " microsseconds");
}