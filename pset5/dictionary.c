/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define APOSTROPH 39

Dictionary *g_pDict;

/**
* Convert ascii char to index
*/
int getIndex(char key)
{
    // last index is for apostroph (ASCII 0x27)
    return key == APOSTROPH ? 26 : key - 'a';
}

/**
 * Insert word into the dictionary. Returns true if successful else false.
 */
bool insertWord(char* word, int len)
{
    Node* pCurrent = g_pDict->root;
    for(int i = 0; i < len; i++)
    {
        char key = tolower(word[i]);
        if ((key >= 'a' && key <= 'z') || key == APOSTROPH) 
        {
            int index = getIndex(key);
            Node* pNext = pCurrent->children[index];
            // if trie does not contain this key on this level
            if (NULL == pNext)
            {
                // allocate new node
                pNext = (Node*) calloc(1, sizeof(Node));
                if (pNext)
                {
                    // link current node to the next
                    pCurrent->children[index] = pNext;
                }
                else
                {
                    return false;
                }
            }
            // move forward
            pCurrent = pNext;
        }
    }
    
    // end of the current word
    pCurrent->isWord = true;
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    Node* pCurrent = g_pDict->root;
    for(int i = 0, len = strlen(word); i < len; i++)
    {
        char key = tolower(word[i]);
        Node* pNext = pCurrent->children[getIndex(key)];
        // if node is not found
        if (pNext == NULL)
        {
            return false;
        }

        // move forward
        pCurrent = pNext;
    }
    return pCurrent->isWord;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* pFile = fopen(dictionary, "r");

    if (pFile)
    {
        // alocate new dictionary
        if (NULL == g_pDict)
        {
            g_pDict = (Dictionary*) calloc(1, sizeof(Dictionary));
            g_pDict->root = (Node*) calloc(1, sizeof(Node));
        }
        
        // LEGTH + 2 -> word + newline + terminating zero   
        char buffer[LENGTH + 2] = {0};
        while(fgets(buffer , LENGTH + 2 , pFile) != NULL)
        {
            int len = strlen(buffer);
            if (len > 0)
            {
                // remove newline char
                buffer[len - 1] = '\0';
                
                if (false == insertWord(buffer, len - 1))
                {
                    fclose(pFile);
                    return false;
                }
                g_pDict->size++;
            }
        }
        fclose(pFile);
        g_pDict->loaded = true;
        return true;
    }
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (g_pDict && g_pDict->loaded)
    {
        return g_pDict->size;
    }
    return 0;
}

/**
 * Free memory allocated for node and his children
 */
void freeNode(Node* pNode)
{
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        Node *pChild = pNode->children[i];
        if (pChild)
        {
            freeNode(pChild);
        }
    }
    
    free(pNode);
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    if (g_pDict)
    {
        if(g_pDict->root)
        {
            freeNode(g_pDict->root);
        }
        free(g_pDict);
        return true;
    }
    
    return false;
}
