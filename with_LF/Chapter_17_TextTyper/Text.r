/* Chapter 17 - TextTyper */
/* Text.r */


// Copyright© 1993, Neil Rhodes and Julie McKeehan. All rights reserved.  

#include "Types.r"
#include "sysTypes.r"

resource 'WIND' (500, "Text window", purgeable, preload) { 
    {68, 44, 254, 286},
    zoomDocProc,
    invisible,
    goAway,
    0x0,
    Untitled
};

resource 'BNDL' (128) {
    'C++2' ,
    0,
    {
        'FREF',
        {
            0, 128
        },
        'ICN#',
        {
            0, 128
        }
    }
};

data 'C++2' (0, "Owner resource") { 
    $"00"
};

data 'FREF' (128) { 
    $"4150 504C 0000 84"
};

resource 'ics#' (128) {
{       /* array: 2 elements */ 
        /* [1] */
        $"0000 0000 0000 3FF8 0100 0100 0100 0100"
        $"0100 0100 0100 0100 0100 01",
        /* [2] */
        $"0000 0000 7FFC 7FFC 7FFC 0380 0380 0380"
        $"0380 0380 0380 0380 0380 0380 0380"
    }
};

resource 'ICN#' (128) {
{       /* array: 2 elements */
        /* [1] */
        $"0000 0000 0000 0000 0000 0000 0000 0000"
        $"0FFF FE00 0FFF FE00 000E 0000 000E 0000"
        $"000E 0000 000E 0000 000E 0000 000E 0000"
        $"000E 0000 000E 0000 000E 0000 000E 0000"
        $"000E 0000 000E 0000 000E 0000 000E 0000"
        $"000E 0000 000E",
        /* (2) */ 
        $"0000 0000 0000 0000 0000 0000 1FFF 0000"
        $"1FFF FF00 1FFF FF00 1FFF FF00 001F 0000"
        $"001F 0000 001F 0000 001F 0000 001F 0000"
        $"001F 0000 001F 0000 001F 0000 001F 0000"
        $"001F 0000 001F 0000 001F 0000 001F 0000"
        $"001F 0000 001F 0000 001F"
    }
};

resource 'MENU' (2, "File", preload) {
    2,
    textMenuProc,
    0X7FFFFFFE,
    enabled,
    "File", 
    {
        "New#2", noIcon, "N", noMark, plain , 
        "Open#3", noIcon, "O", noMark, plain,
        "-", noIcon, noKey, noMark, plain, 
        "Close#4", noIcon, "W", noMark, plain, 
        "Save#5", noIcon, "S", noMark, plain,
        "Save As_#6", noIcon, noKey, noMark, plain, 
        "-", noIcon, noKey, noMark, plain,
        "Page Setup_#8", noIcon, noKey, noMark, plain,
        "Print_#9", noIcon, "P", noMark, plain,
        "-", noIcon, noKey, noMark, plain, 
        "Quit#1", noIcon, "Q", noMark, plain
    }
};

resource 'MBAR' (1, preload) { 
    { 1, 2, 3
    } 
};

resource 'SICN' (200, "TCL sicns", purgeable, preload) {
    {
        $"FFFF 8001 8001 9FC1 9041 9070 9045 9045" 
        $"9045 9FC5 8405 8405 8405 87FD 8001 FFFF", 
        $"07FF 03FE 01FC 00F8 0070 0020"
    } 
};


resource 'WIND' (200, "Clipboard", purgeable, preload) {
    {130, 158, 238, 444},
    zoomDocProc,
    invisible,
    goAway,
    0x0,
    "Clipboard" 
};

resource 'MENU' (3, "Edit", preload) {
    3,
    textMenuProc,
    0x7FFFFF80,
    enabled,

    "Edit",
    {
        "Undo#16", noIcon, "Z", noMark, plain,
        "-", noIcon, noKey, noMark, plain,
        "Cut#18", noIcon, "X", noMark, plain,
        "Copy#19", noIcon, "C", noMark, plain,
        "Paste#20", noIcon, "V", noMark, plain, 
        "Clear#21", noIcon, noKey, noMark, plain, 
        "Select All#23", noIcon, "A", noMark, plain,
         "-", noIcon, noKey, noMark, plain,
        "Show Clipboard#22", noIcon, noKey, noMark, plain
    }
};

resource 'MENU' (1, "Apple", preload) {
    1,
    textMenuProc,
    0x7FFFFFFD,
    enabled,
    apple,
    {
        "About TextTyper_#256", noIcon, noKey, noMark, plain, 
        "-", noIcon, noKey, noMark, plain
    }
};

resource 'CNTL' (300, "Scroll Bar", preload) {
    {0, 0, 0, 0},
    0,
    visible,
    0,
    0,
    scrollBarProc,
    0,
    ""
};

resource 'MENU' (10, "Font") { 
    10,
    textMenuProc,
    allEnabled,
    enabled,
    "Font",
    {
    }
};


resource 'MENU' (11, "Size") {
    11,
    textMenuProc,
    allEnabled,
    enabled, 
    "Size",
    {
    } 
};

resource 'MENU' (12, "Style") { 12,
textMenuProc, allEnabled, enabled, "Style",
    {
        "Plain Text#30", noIcon, "P", check, plain, 
        "Bold#31", noIcon, "B", noMark, 1, 
        "Italic#32", noIcon, "I", noMark, 2, 
        "Underline#33", noIcon, "U", noMark, 4, 
        "Outline#34", noIcon, noKey, noMark, 8, 
        "Shadow#35", noIcon, noKey, noMark, 16, 
        "Condensed#36", noIcon, noKey, noMark, 32, 
        "Extended#37", noIcon, noKey, noMark, 64
    }
};




