#include <stdio.h>
#include <string.h>
#include <cs50.h>

// encrypt message with Caesar cipher
void encryptCaesar(string message, int key)
{
    for(int i = 0, message_len = strlen(message); i < message_len; i++)
    {
        char ch = message[i];
        // encrypt upper case letters
        if ((ch >= 'A' && ch <= 'Z'))
        {
            char encryptedChar = ((ch + key - 'A') % 26) + 'A';
            printf("%c", encryptedChar);
        }
        // encrypt lower case letters
        else if (ch >= 'a' && ch <= 'z')
        {
            char encryptedChar = ((ch + key - 'a') % 26) + 'a';
            printf("%c", encryptedChar);    
        }
        // just print other characters
        else
        {
            printf("%c", ch);
        }
    }
    printf("\n");
}

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments!\n");
        return 1;
    }
    
    // convert key from string to interger
    int key = atoi(argv[1]);
    
    string message = GetString();
    encryptCaesar(message, key);
    
    return 0;
}