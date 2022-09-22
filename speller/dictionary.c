// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int sizec = 1;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    node *n = NULL;
    while (!feof(file))
    {
        n = calloc(1, sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        sizec += fscanf(file, "%s", n->word);


        if (n->word[0] != '\0')
        {
            if (table[hash(n->word)] == NULL)
            {
                table[hash(n->word)] = n;
            }
            else
            {
                n->next = table[hash(n->word)];
                table[hash(n->word)] = n;
            }
        }

    }
    free(n);
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return sizec;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    node *cursor = table[0];
    ;
    for (int i = 0; i < 26; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            table[i] = cursor->next;
            free(cursor);
            cursor = table[i];
        }
    }

    return true;
}
