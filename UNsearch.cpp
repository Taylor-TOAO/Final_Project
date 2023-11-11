#include "UNsearch.h"


int searchList(string user_name[], int size, string UN)
{
    bool flag = false;
    int index = 0;
    int position = -1;

    while (index < size && !flag)
    {
        if (UN == user_name[index])
        {
            flag = true;
            position = index;
        }
        index++;
    }
    return position;
}