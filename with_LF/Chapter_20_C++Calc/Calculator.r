/* Chapter 20 - C++Calc */
/* Calculator.r */


// Copyright© 1993-94, Neil Rhodes and Julie McKeehan. All rights reserved. 
// Calculator.r

#include "Types.r" 
#include "SysTypes.r"

resource 'MBAR' (1, preload) {
    { 1, 2, 3
    }
};

resource 'ALRT' (1024, "kAlertResourceID") {
    {40, 40, 184, 276},
    1024,
    {    /* array: 4 elements */
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
            "^0, from Symantec C++ Programming for the Macintosh, ©1993-94 b"
            "y Neil Rhodes and Julie McKeehan, Brady "
            "Books"
        },
        {116, 147, 136, 205},
        Button {
            enabled,
            "OK"
        }
    }
};

resource 'STR#' (1025, "button names", purgeable, preload) {
    {
        "+",
        "*",
        "/",
        "-",
        "Ent",
        ".",
        "E",
        "CE",
        "±",
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    } /*TYPO???*/
};

resource 'WIND' (500, "C++ Cale", purgeable, preload) { 
    {68, 44, 216, 150},
    rDocProc,
    invisible,
    goAway, 
    0x0,
    "C++ Cale" 
};

resource 'BNDL' (128) { 
    'C++6',
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

data 'C++6' (0, "Owner resource") { 
    $"00"
};

data 'FREF' (128) { 
    $"4150 504C 0000 84"
};

resource 'ics#' (128) {
    {   /* array: 2 elements */
        /* [1] */
        $"3FE0 4010 4010 7FF0 4010 5550 4010 5550"
        $"4010 5550 4010 5550 4010 4550 4010 3FE0",
        /* [2] */ 
        $"3FE0 7FF0 7FF0 7FF0 7FF0 7FF0 7FF0 7FF0"
        $"7FF0 7FF0 7FF0 7FF0 7FF0 7FF0 7FF0 3FE0"
    }
};

resource 'ICN#' (128) {
    {   /* array: 2 elements */
        /* [1] */ 
        $"1FFF FF80 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"2000 0040 27FF FE40 2400 0240 2400 0240"
        $"27FF FE40  2000 0040 2739 CE40 2529 4A40"
        $"2739 CE40  2000 0040 2739 CE40 2529 4A40"
        $"2739 CE40  2000 0040 2739 CE40 2529 4A40"
        $"2739 CE40  2000 0040 2739 CE40 2529 4A40"
        $"2739 CE40  2000 0040 2039 CE40 2029 4A40"
        $"2039 CE40  2000 0040 1000 0080 0FFF FF",
        /* [2) */ 
        $"1FFF FF80 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 3FFF FFC0 3FFF FFC0"
        $"3FFF FFC0 3FFF FFC0 1FFF FF80 0FFF FF"
    }
};

resource 'vers' (1) { 
    0x1,
    0x1,
    release,
    0x0,
    verUS,
    "C++ Calc 1.1",
    "1.1, from Symantec C++ Programming fort" "he Macintosh."
};

resource 'vers' (2) { 0x1,
    0x1,
    release,
    0x0,
    verUS,
    "C++ Calc 1.0",
    "1.1 ©1993-94, Rhodes and McKeehan."
};

resource 'MENU' (2, "File", preload) { 
    2,
    textMenuProc,
    0x7FFFFFFE,
    enabled,
    "File",
    {
        "Close#4" ,noIcon,"W", noMark, plain,
        "Quit#1 ", noIcon, "Q", noMark, plain

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
    textMenuProc, 0x7FFFFF80, enabled,
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
        "About C++ Calc_#256", noIcon, noKey, noMark, plain, 
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






