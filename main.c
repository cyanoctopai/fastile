/*
================================================
 ______       _____ _______ _____ _      ______ 
|  ____/\    / ____|__   __|_   _| |    |  ____|
| |__ /  \  | (___    | |    | | | |    | |__   
|  __/ /\ \  \___ \   | |    | | | |    |  __|  
| | / ____ \ ____) |  | |   _| |_| |____| |____ 
|_|/_/    \_\_____/   |_|  |_____|______|______|

================================================
Author  : jzaunegger
Version : 0.0.1 
================================================

This program is used to quickly take a large image and break it into many smaller, potentially overlapping
image tiles. It can also be used to chip out regions from source image and save them off to separate files.


This codebase is designed to be used as a stand-alone tool or be used as a lower-level implementation that
can be called by higher-level languages like Python.

*/
#include <stdio.h>
#include <string.h>

// Define constants
char VERSION_NUM[5] = "0.0.1";

void bbox_xyxy_to_cxcywh(int x1, int y1, int x2, int y2){
    /* Convert a bounding box from xyxy to cxcywh

    This function is used to convert a provided bounding box from Top-Left / Bottom Right (x1, y1, x2, y2)
    format to Center Point / Width and Height format (cx, cy, w, h).

    Parameters
    ----------
    x1: int
        The x component of the top-left coordinate.
    y1: int
        The y component of the top-left coordinate.
    x2: int
        The x component of the bottom-right coordinate.
    y2: int
        The y component of the bottom-right coordinate.

    Returns
    -------
    */
    
    int width = x2 - x1;
    int height = y2 - y1;
    int cx = x1 + (width / 2);
    int cy = y1 + (height / 2);
}





void log_header(){
    /*Log the header of the application to the console.

    Parameters
    ----------

    Returns
    -------
    None
    */
    printf("\n");
    printf("================================================\n");
    printf(" ______       _____ _______ _____ _      ______ \n");
    printf("|  ____/\\    / ____|__   __|_   _| |    |  ____|\n");
    printf("| |__ /  \\  | (___    | |    | | | |    | |__   \n");
    printf("|  __/ /\\ \\  \\___ \\   | |    | | | |    |  __|  \n");
    printf("| | / ____ \\ ____) |  | |   _| |_| |____| |____ \n");
    printf("|_|/_/    \\_\\_____/   |_|  |_____|______|______|\n");
    printf("\n");
    printf("================================================\n");
    printf("Author  : jzaunegger\n");
    printf("Version : %s\n", VERSION_NUM);
    printf("================================================\n");
    printf("\n");
}

void log_help(){
    /* Log the help information to the console.
    
    Parameters
    ---------
    None

    Returns
    -------
    None
    */
    printf(" Commands: \n");
    printf(" --------------------- \n");
    printf(" tile -- Used to tile a large image into smaller sections.\n");
    printf("\n");
    printf(" chip -- Used to chip out a small section of a larger image.\n");
    printf(" Options:\n");
    printf("   --img-path, -i  : The file path to the image to chip. \n");
    printf("   --chip-list, -c : The file path to a text file containing the coordinates / regions of the image to chip. \n");
    printf("   --box-fmt, -b   : The format of the coordinates / regions. Can take on the following values: \n");
    printf("                       'xyxy'   -- Top-Left / Bottom Right \n");
    printf("                       'xywh'   -- Top-Left / Width and Height \n");
    printf("                       'cxcywh' -- Center X/Y / Width and Height \n");
    printf("\n");
    
}


int main(int argc, char *argv[]){
    /*Define the program entrypoint
    
    Parameters
    ----------
    argc: int
        The number of parsed command-line arguments.
    argv[]: char
        A array of strings containing the parsed command-line arguments.

    Returns
    -------
    int
        0 if the program exited successfully, 1 otherwise.
    */
    log_header();

    // printf("Program Name: %s\n", argv[0]);
    // printf("Number of arguments: %d\n\n", argc - 1);
    // for (int i = 1; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }

    // Check if the help option was invoked
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
        log_help();
    }

    // Check if the chipping option was invoked
    else if( strcmp(argv[1], "chip") == 0 ){
        printf("Running chipping sub-routine. \n");
    }

    // Check if the tiling option was invoked
    else if ( strcmp(argv[1], "tile") == 0) {
        printf("Running tiling sub-routine. \n");
    }

    // Exit the program
    else {
        printf("Command '%s' is not recognized. \n", argv[1]);
        return 1;
    }
    return 0;
}