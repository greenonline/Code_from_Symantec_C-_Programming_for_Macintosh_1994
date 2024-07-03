/* Chapter 16 - RandomRectangle */
/* Rectangle.r */

// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 
// Rectangle.r

#include "Types.r" 
#include "SysTypes.r"
resource 'BNDL' (128) { 
    'C++1',
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

data 'C++1' (0, "Owner resource") { 
    $"00"
};

data 'FREF' ( 128) { 
    $"4150 504C 0000 84"
};

resource 'ICN#' (128) {

    {
        $"0000 0000 0000 0000 003F FE00 0020 0200"
        $"0020 0200 03FF F200 0220 1200 0220 1200"
        $"0220 1200 0220 1200 0FFE 1200 0A22 1200"
        $"0A22 1200 0A22 1200 0BFF F200 0822 0200"
        $"083F FE00 0802 0000 0FFE",
        $"0000 0000 0000 0000 003F FE00 003F FE00"
        $"003F FE00 03FF FE00 03FF FE00 03FF FE00"
        $"03FF FE00 03FF FE00 0FFF FE00 0FFF FE00"
        $"0FFF FE00 0FFF FE00 0FFF FE00 0FFF FE00"
        $"0FFF FE00 0FFE 0000 0FFE"
    }
};


resource 'ics#' (128) { 
    {
        $"01FE 0102 1FF2 1112 FFD2 9152 9152 91FE" 
        $"9050 9FF0 8040 8040 FFC0",
        $"01FE 01FE 1FFE 1FFE FFFE FFFE FFFE FFFE" 
        $"FFF0 FFF0 FFC0 FFC0 FFC0"
    }
};

resource 'vers' (1) { 
    0x1,
    0x1,
    release,
    0x0,
    verUS, 
    "RandomRectangles 1.1",
    "1.1, from Symantec C++ Programming for t"
    "he Macintosh."
};


resource 'vers' (2) { 0x1,
    0x1,
    release,
    0x0,
    verUS,
    "RandomRectangles 1.1",
    "1.1 ©1993-94, Rhodes and McKeehan."
};


 resource 'MENU' (2, "File", preload) { 
    2,
    textMenuProc,
    0x7FFFFFFE,
    enabled,
    "File", 
    {
        "Close#4", noIcon, "W", noMark, plain,
        "Quit#1", noIcon, "Q", noMark, plain
    } 
};


resource 'MBAR' (1, preload) { 
    { 1, 2, 3
    } 
};

resource 'SICN' (200, "TCL sicns", purgeable, preload) {
    {
        $"FFFF 8001 8001 9FC1 9041 907D 9045 9045" 
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

resource 'WIND' (500, "Rectangle window", purgeable, preload) { 
    {68, 44, 254, 286},
    zoomDocProc,
    visible,
    goAway, 
    0x0, 
    Untitled
};


resource 'MENU' (3, "Edit", preload) { 
    3,
    textMenuProc, 
    0x7FFFFF80, 
    enabled,
    "Edit", 
    {
        "Undo#16", noIcon, "Z", noMark, plain ,
        "-", noIcon, noKey, noMark, plain,
        "Cut#18", noIcon, "X", noMark, plain,
        "Copy#19", noIcon , "C", noMark, plain,
        "Paste#20", noIcon, "V", noMark, plain, 
        "Clear#21", noIcon, noKey, noMark, plain,
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
        "About RandomRectangles_#256", noIcon, noKey, noMark, plain, 
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

