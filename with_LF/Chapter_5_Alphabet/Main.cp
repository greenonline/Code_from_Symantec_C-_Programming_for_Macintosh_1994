/* Chapter 5 - Alphabet */
/* Main.cp */

#include <stdio.h>
#include <Types.h>
#include <OSUtils.h>
#include <string.h>
#include <ToolUtils.h>
#include "ResourceDefinitions.h"

#define kMaxInputLine 512

/* prompt for character input */ 
char gPrompt[256];

/* if they type an invalid character */ 
char gBadCharacter[256];

/* output if they type a valid character. This is used as the first argument to printf */
char gCharIsForWordTemplate[256];

Boolean FindIndexOfCharacter(char c, int *ip) {
    const kCaseSensitive = true;
    const kDiacriticalSensitive = true;
    Str255 entry;
    int index = 0;
    Str255 charAsString;

    charAsString[0] = 1;
    charAsString[1] = c;


    do {
        GetIndString(entry, kCharsResourceID, ++index);
    } while (StrLength(entry) != 0 && 
         !EqualString(charAsString, entry,
           !kCaseSensitive, !kDiacriticalSensitive));
    *ip = index;
    return StrLength(entry) != 0;
}


/* returns false if no more input */ 
Boolean HandleOneInteraction()
{
    int c;
    char inputLine[kMaxInputLine];

    printf("\n%s", gPrompt);
    if (fgets(inputLine, sizeof(inputLine), stdin) == NULL)
        return false; 
    else {
        int i;

        if (!FindIndexOfCharacter(*inputLine, &i)) printf("%s\n", gBadCharacter);
        else {
            Str255 word;

            GetIndString(word, kWordsResourceID, i); 
            printf(gCharIsForWordTemplate, *inputLine, p2cstr(word)); 
            putchar('\n');
        }
        return true;
    }
}

void InitializeStrings()
{
    Str255 s;

    GetIndString(s, kMiscStringsID, kPromptItem);
    strcpy(gPrompt, p2cstr(s));

    GetIndString(s, kMiscStringsID, kBadCharacterItem); 
    strcpy(gBadCharacter, p2cstr(s));

    GetIndString(s, kMiscStringsID, kTemplateItem);
    strcpy(gCharIsForWordTemplate, p2cstr(s));
}

main()
{

    InitializeStrings();
    while (HandleOneInteraction())
    {
        /* do nothing */
    }
    return 0;
}