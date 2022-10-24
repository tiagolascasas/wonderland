"use strict";

class Tool {
    toolName;
    disableWeaving;

    constructor(toolName, disableWeaving) {
        if (this.constructor == Tool) {
            throw new Error("Class 'Tool' is abstract and cannot be instantiated");
        }

        this.toolName;
        this.disableWeaving = defaultValue(disableWeaving, false);
    }

    addCurrentAst() {
        for (var userInclude of Clava.getData().getUserIncludes()) {
            println("[" + this.toolName + "] Adding include: " + userInclude);
            this.addIncludeFolder(userInclude);
        }

        // Write current version of the files to a temporary folder and add them
        var currentAstFolder = Io.getPath(Io.getTempFolder(), "tempfolder_current_ast");

        // Clean folder
        Io.deleteFolderContents(currentAstFolder);

        // Create and populate source folder
        var srcFolder = Io.getPath(currentAstFolder, "src");
        for (var $file of Clava.getProgram().descendants("file")) {
            var destFolder = srcFolder;
            //if($file.relativeFolderpath !== undefined) {
            //	destFolder = Io.mkdir(srcFolder, $file.relativeFolderpath);
            //}
            var filepath = $file.write(destFolder.toString());

            if (!$file.isHeader) {
                this.getSources().addSource(filepath);
            }
            //println("Written file:" + filepath);
        }

        // Add src folder as include
        this.addIncludeFolder(srcFolder);

        return this;
    }

}