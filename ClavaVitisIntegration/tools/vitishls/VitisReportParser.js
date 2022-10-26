"use strict";

class VitisReportParser {
    reportPath;

    constructor(reportPath) {
        this.reportPath = reportPath;
    }

    #xmlToJson(xml) {
        //https://www.delftstack.com/howto/javascript/javascript-xml-to-json/
        //not a great solution. parsing is incomplete, but that is enough for us

        const jsonData = {};
        for (const result of xmlString.matchAll(/(?:<(\w*)(?:\s[^>]*)*>)((?:(?!<\1).)*)(?:<\/\1>)|<(\w*)(?:\s*)*\/>/gm)) {
            const key = result[1] || result[3];
            const value = result[2] && this.#xmlToJson(result[2]); //recusrion
            jsonData[key] = ((value && Object.keys(value).length) ? value : result[2]) || null;
        }
        return jsonData;

        return json;
    }

    getSanitizedJSON() {
        const raw = this.#getRawJSON();

        const fmax = this.calculateMaxFrequency(raw["EstimatedClockPeriod"]);
        const execTime = this.calculateExecutionTime(raw["Latency"], fmax);

        var json = {
            "platform": raw["Part"],
            "topFun": raw["TopModelName"],
            "clockTarget": raw["TargetClockPeriod"],
            "clockEstim": raw["EstimatedClockPeriod"],
            "fmax": fmax,
            "execTime": execTime,
            "FF": raw["FF"],
            "LUT": raw["LUT"],
            "BRAM": raw["BRAM_18K"],
            "DSP": raw["DSP"],
            "latency": raw["Latency"],
            "availFF": raw["AVAIL_FF"],
            "availLUT": raw["AVAIL_LUT"],
            "availBRAM": raw["AVAIL_BRAM"],
            "availDSP": raw["AVAIL_DSP"],
            "perFF": raw["FF"] * 100 / raw["AVAIL_FF"],
            "perLUT": raw["LUT"] * 100 / raw["AVAIL_LUT"],
            "perBRAM": raw["BRAM_18K"] * 100 / raw["AVAIL_BRAM"],
            "perDSP": raw["DSP"] * 100 / raw["AVAIL_DSP"]
        };
        return json;
    }

    #getRawJSON() {
        const xml = Io.readFile(this.reportPath);
        return this.#xmlToJson(xml);
    }

    calculateMaxFrequency(clockEstim) {
        return (1 / clockEstim) * 1000;
    }

    calculateExecutionTime(latency, freqMHz) {
        const freqHz = freqMHz * 1e6;
        return latency / freqHz;
    }
}