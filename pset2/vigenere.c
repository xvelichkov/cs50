#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// encrypt message with Caesar cipher
void encryptCaesar(char ch, int key)
{
    // encrypt upper case characters
    if ((ch >= 'A' && ch <= 'Z'))
    {
        char encryptedChar = ((ch + key - 'A') % 26) + 'A';
        printf("%c", encryptedChar);
    }
    // encrypt lower case characters
    else if (ch >= 'a' && ch <= 'z')
    {
        char encryptedChar = ((ch + key - 'a') % 26) + 'a';
        printf("%c", encryptedChar);    
    }
}

// convert english charater from ascii to number
// A,a = 0 ... Z,z = 25
int getKey(char key_char)
{
    int key = 0;
    if (key_char >= 'A' && key_char <= 'Z')
    {
        key = key_char - 'A';
    }
    
    if (key_char >= 'a' && key_char <= 'z')
    {
        key = key_char - 'a';
    }
    
    return key;
}

// encrypt message with Vigenere cipher
void encryptVigenere(string message, string key)
{
    int key_len = strlen(key);
    int key_index = 0;
    for(int i = 0, message_len = strlen(message); i < message_len; i++)
    {
        char ch = message[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            encryptCaesar(ch, getKey(key[key_index]));
            // update key_index only if charachter is alphabetical
            key_index++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            encryptCaesar(ch, getKey(key[key_index]));
            // update key_index only if charachter is alphabetical
            key_index++;
            
        }
        else
        {
            printf("%c", ch);
        }

        // reset key index
        if (key_index > (key_len - 1))
        {
            key_index = 0;
        }
    }
    printf("\n");
}

// check if keyword contains only alphabetical characters
bool checkKeyword(string key)
{
    for(int i = 0, key_len = strlen(key); i < key_len; i++)
    {
        if (false == isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Not enough or too much arguments!\n");
        return 1;
    }
    
    string key = argv[1];
    if (false == checkKeyword(key))
    {
        printf("Keyword contains non-alphabetical characters\n");
        return 1;
    }
    
    
    string message = GetString();
    encryptVigenere(message, key);
    
    return 0;
}