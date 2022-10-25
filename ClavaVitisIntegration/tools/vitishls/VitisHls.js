"use strict";

laraImport("clava.Clava");
laraImport("lara.util.ProcessExecutor");
laraImport("tools.Tool");
laraImport("tools.vitishls.VitisReportParser");

class VitisHls extends Tool {
    topFunction;
    platform;
    clock;
    vitisDir;
    vitisProjName;
    sourceFiles = [];

    constructor(disableWeaving) {
        super("VitisHls", disableWeaving);

        this.topFunction = undefined;
        this.platform = undefined;
        this.clock = undefined;
        this.vitisDir = "VitisHLS";
        this.vitisProjName = "vitis_hls_project";
    }

    setTopFunction(topFunction) {
        this.topFunction = topFunction;

        return this;
    }

    setPlatform(platform) {
        this.platform = platform;
        return this;
    }

    setClock(clock) {
        if (clock <= 0) {
            throw new Error("Clock value must be a positive integer!");
        } else {
            this.clock = clock;
        }
        return this;
    }

    addSource(file) {
        this.sourceFiles.push(file);
    }

    synthesize(verbose = true) {
        Io.deleteFolderContents(this.vitisDir);
        this.#generateTclFile();
        this.#executeVitis(verbose);
        return Io.isFile(this.#getSynthesisReportPath());
    }

    #getSynthesisReportPath() {
        var path = this.vitisDir + "/" + this.vitisProjName;
        path += "/solution1/syn/report/csynth.xml";
        return path;
    }

    #executeVitis(verbose) {
        const pe = new ProcessExecutor();
        pe.setWorkingDir(this.vitisDir);
        pe.setPrintToConsole(verbose);
        pe.execute("vitis_hls", "-f", "script.tcl");
    }

    #getTclInputFiles() {
        var str = "";
        // make sure the files are woven
        Clava.writeCode(Clava.getWeavingFolder());

        // if no files were added, we assume that every woven file should be used
        if (this.sourceFiles.length == 0) {
            for (var file of Io.getFiles(Clava.getWeavingFolder())) {
                const exts = [".c", ".cpp", ".h", ".hpp"];
                const res = exts.some(ext => file.name.includes(ext));
                if (res)
                    str += "add_files ../woven_code/" + file.name + "\n"
            }
        }
        else {
            for (const file of this.sourceFiles) {
                str += "add_files ../woven_code/" + file + "\n";
            }
        }
        return str;
    }

    #generateTclFile() {
        var cmd = "open_project " + this.vitisProjName + "\n";
        cmd += "set_top " + this.topFunction + "\n";
        cmd += this.#getTclInputFiles();
        cmd += "open_solution \"solution1\" -flow_target vitis\n";
        cmd += "set_part {" + this.platform + "}\n";
        cmd += "create_clock -period " + this.clock + " -name default\n";
        cmd += "csynth_design\n";
        cmd += "exit\n";

        Io.writeFile(this.vitisDir + "/script.tcl", cmd);
    }

    getSynthesisReport() {
        const parser = new VitisReportParser(this.#getSynthesisReportPath());
        const json = parser.getSanitizedJSON();
        return json;
    }

    prettyPrintReport(report) {
        println("Vitis HLS synthesis report");
        println("--------------------------");
        println("Targeted a " + report["platform"] + ", with target clock " + report["clockTarget"] + "ns");
        println("");
        println("Achieved an estimated clock of " + report["clockEstim"] + "ns (" + report["fmax"] + "MHz)");
        println("");
        println("Latency of " + report["latency"] + " cycles for top function " + report["topFun"]);
        println("Estimated execution time of " + report["execTime"] + "s");
        println();
        println("Resource usage:");
        println("FF: " + report["FF"] + "(" + report["perFF"] + "%)");
        println("LUT: " + report["LUT"] + "(" + report["perLUT"] + "%)");
        println("BRAM: " + report["BRAM"] + "(" + report["perBRAM"] + "%)");
        println("DSP: " + report["DSP"] + "(" + report["perDSP"] + "%)");
        println("--------------------------");
    }
}