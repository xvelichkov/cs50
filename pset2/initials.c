#include <stdio.h>
#include <cs50.h>

#include <string.h> //strlen
#include <ctype.h> //toupper

int main(void)
{
    string name = GetString();
    
    // print first character
    printf("%c", toupper(name[0]));
    for(int i = 0, name_len = strlen(name); i < name_len; i++)
    {
        if (name[i] == ' ')
        {
            // print first character of the word
            // and increment i
            printf("%c", toupper(name[++i]));
        }
    }
    printf("\n");
    
    return 0;
}