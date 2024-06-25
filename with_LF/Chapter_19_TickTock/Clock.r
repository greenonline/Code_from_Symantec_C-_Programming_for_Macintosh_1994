/* Chapter 19 - TickTock */
/* Clock.r */



// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 

#include "Types.r"
#include "SysTypes.r"

resource 'MENU' (4, "Clock", preload) { 
    4,
    textMenuProc, 
    0x7FFFFFFF, 
    enabled,
    "Clock", 
    {
        "Show seconds#1024", noIcon, noKey, noMark, plain, 
        "-", noIcon, noKey, noMark, plain,
        "Digital#1025", noIcon, noKey, noMark, plain,
        "Analog#1026", noIcon, noKey, noMark, plain,
    } 
};

resource 'MBAR' (1, preload) {
    { 1,2,3,4
    } 
};

resource 'ALRT' (1024, "kAlertResourceID") { 
    { 40, 40, 184, 276},
    1024, 
    {   /* array: 4 elements */ 
        OK, visible, sound1, 
        OK, visible, sound1, 
        OK, visible, sound1, 
        OK, visible, sound1
    } 
};



resource 'DITL' (1024, "kAlertResourceID") { 
    {
        {5, 12, 93, 228}, 
        StaticText {
            disabled,

            "^0, from Symantec C++ Programming for the Macintosh, ©1993-94" 
            "by Neil Rhodes and Julie McKeehan, Brady "
            "Books"
        },
        {116, 147, 136, 205},
        Button {
            enabled, 
            "OK"
        }
    }
};

resource 'WIND' (500, "Clock window", purgeable, preload) { 
    {68, 44, 168, 144},
    documentProc,
    invisible,
    goAway, 
    0x0, 
    "Clock"
};

resource 'BNDL' (128) { 
    'C++5',
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

data 'C++5' (0, "owner resource") { 
    $"00"
};

data 'FREF' (128) { 
    $"4150 504C 0000 84"
};

resource 'ICN#' (128) {


    {   /* array: 2 elements */
        /* [1] */
        $"0000 0000 0000 0000 0003 8000 000C 6000"

        $"0018 3000  2410 1004 A81F F015 7078 3C0E"

        $"7CE0 0E3E  70C0 030E 3181 018C 3301 00CC"

        $"3301 00CC  3E01 007C 3E01 007C 0601 0060"
        $"0601 FC60  0602 0060 0604 0060 0608 0060"
        $"0310 00C0  0320 00C0 0180 0180 00C0 0300"
        $"00F0 0F00  007F FE00 007F FE00 0070 0E00"
        $"0060 0600  0060 0600 00F0 0F00 01F8 1F80",
        /* [2] */ 
        $"0000 0000 0000 0000 0003 8000 000F E000"
        $"001F F000  241F F004 A81F F015 707F FC0E"
        $"7CFF FE3E  70FF FF0E 31FF FF8C 33FF FFCC"
        $"33FF FFCC  3FFF FFFC 3FFF FFFC 07FF FFE0"
        $"07FF FFE0  07FF FFE0 07FF FFE0 07FF FFE0"
        $"03FF FFC0  03FF FFC0 01FF FF80 00FF FF00"
        $"00FF FF00  007F FE00 007F FE00 0070 0E00"
        $"0060 0600 0060 0600 00F0 0F00 01F8 1F80"
    }
};

resource 'ics#' (128) {
    {   /* array: 2 elements */
        /* [1] */
        $"07C0 1830 2108 4104 4104 8102 8102 81F2"
        $"8202 8402 4804 4004 2008 1830 1FF0 701C",
        /* [2] */
        $"07C0 1FF0 3FF8 7FFC 7FFC FFFE FFFE FFFE"
        $"FFFE FFFE 7FFC 7FFC 3FF8 1FF0 1FF0 701C"
    }
};

resource 'vers' (1) { 
    0x1,
    0x1,
    release,
    0x0,
    verUS,
    "PICTPeeker 1.1 ",
    "1.1, from Symantec C++ Programming for t"
    "he Macintosh."
};

resource 'vers' (2) { 
    0x1,
    0x1,
    release,
    0x0,
    verUS,
    "PICTPeeker 1.1",
    "1.1 ©1993-94, Rhodes and McKeehan."
};

resource 'MENU' (2, "File", preload) { 
    2,
    textMenuProc, 
    0x7FFFFFFE, 
    enabled, 
    "File",
    {
        "Close#4", noIcon, "W", noMark, plain
        "-", noIcon, noKey, noMark, plain,
        "Quit#1 ", noIcon, "Q", noMark, plain }
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
        "cut#18", noIcon, "X", noMark, plain, 
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
        "About Tick-Tock_#256", noIcon, noKey, noMark, plain, 
        "-", noIcon, noKey, noMark, plain
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

resource 'CNTL' (300, "Scroll Bar", preload) { 
    {0, 0, 0, 0},
    0,
    visible,
    0,
    0, 
    scrollBarProc, 
    0,
    "",
};
