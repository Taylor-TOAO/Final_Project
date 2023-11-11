#include "PWsearch.h"


int searchPWList(string pass_word[], int size, string PW, int result)
{
    bool match = true;
    for (int k = 0; k < size; k++)
    {
        if (pass_word[k] == PW && result == k)
            match = false;
    }
    return match;
}