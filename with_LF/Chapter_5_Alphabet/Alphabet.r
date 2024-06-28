/* Chapter 5 - Alphabet */
/* Alphabet.r */


#include "Types.r"
#include "ResourceDefinitions.h"
resource 'STR#' (kCharsResourceID, "Characters", purgeable)
{
    {
        "a",  "b", "c", "d", "e", "f", "g",
        "h", "i", "j", "k", "l", "m", "n",
        "o", "p",  "q", "r", "s", "t", "u",
        "v", "w" "x", "y", "z"
    } 
};

resource 'STR#' (kWordsResourceID, "Words", purgeable) {
    {
        "Alexander", "Barnacle", "Cornelius", 
        "Daddy", "Elephant", "Fox",
        "Gazelle", "Horse", "Iguana",
        "Jagular", "Kanga", "Limpet",
        "Mommy", "Nicholas", "Ostrich",
        "Peacock", "Quetzal", "Richard",
        "Shira-kan", "Thomas the Train", "Unicornfish",
        "Vulture",  "Walrus", "Xirces",
        "Yo-yo", "Zebra"
    } 
};

resource 'STR#' (kMiscStringsID, "Misc", purgeable)
{
    {
        "Character? ",
        "Invalid character", 
        "%c is for %s"
    }
};