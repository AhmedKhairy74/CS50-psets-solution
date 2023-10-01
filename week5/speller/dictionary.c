// Implements a dictionary's functionality

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 * 26;

// Hash table
node *table[N];

// store number of words
unsigned int dic_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // node *temp = table[hash(word)];

    node *temp = table[hash(word)];
    while (temp->next != NULL)
    {
        if (!strcasecmp(word, temp->word))
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int n = strlen(word);
    if (n > 2)
    {
        return ((toupper(word[0]) - 'A') * 26 * 26) + ((word[1] != '\'') ? (toupper(word[1]) - 'A') * 26 : 0) +
               ((word[2] != '\'') ? (toupper(word[2]) - 'A') : 0);
    }
    else if (n == 2)
    {
        return ((toupper(word[0]) - 'A') * 26 * 26) + ((word[1] != '\'') ? (toupper(word[1]) - 'A') * 26 : 0);
    }
    return (toupper(word[0]) - 'A') * 26 * 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char spell[LENGTH + 1];
    unsigned int h = 0;
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));
        table[i]->next = NULL;
        strcpy(table[i]->word, "Hello!");
    }

    while (fscanf(dic, "%s", spell) != EOF)
    {
        node *n = (node *) malloc(sizeof(node));
        dic_size++;
        h = hash(spell);
        strcpy(n->word, spell);
        n->next = table[h];
        table[h] = n;
    }
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dic_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
    return true;
}
