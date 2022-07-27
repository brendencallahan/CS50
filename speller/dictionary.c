// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Place to count dict entries (idk if global pointers are best practice)
int *dictcount = NULL;
bool *open = NULL;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i = hash(word);
    node *point = table[i];
    while (point != NULL)
    {
        if (strcasecmp(point->word, word) == 0)
        {
            return true;
        }
        point = point->next;
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
    FILE *dict = fopen(dictionary, "r");

    dictcount = malloc(sizeof(int));
    *dictcount = 0;
    open = malloc(sizeof(bool));
    *open = false;
    if (dictcount == NULL || open == NULL)
    {
        printf("Error no memeory");
        return false;
    }

    if (dict == NULL)
    {
        printf("Error loading file");
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            *open = false;
            printf("Error no memory");
            fclose(dict);
            return false;
        }
        *dictcount = *dictcount + 1;
        strcpy(n->word, word);
        int tmp = hash(word);
        n->next = table[tmp];
        table[tmp] = n;
    }

    *open = true;
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (*open == true)
    {
        return *dictcount;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i ++)
    {
        node *current = table[i];
        node *previous = NULL;

        while (current != NULL)
        {
            previous = current;
            current = current->next;
            free(previous);
        }
    }

    free(dictcount);
    free(open);
    return true;
}
