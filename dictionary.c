#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

/*V1 push attempt*/

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

char u_word[46];

unsigned int SIZE = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *current = table[index];
    printf("***************** STARTING CHECK ******************\n");
    printf("%s ---- %u\n", word, index);
    printf("%s\n", table[index]->word);
    int track = 0;
    while (current != NULL) {
        printf("tracker: %d \t %s\n", track, current->word);
        if (strcasecmp(current->word, word) == 0) {
            printf("FOUND: %s\n", current->word);
            printf("---------------------------------------------\n");
            return true;
        }
        current = current->next;
    }
    return false;
}


unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (hash * 31 + tolower(word[i])) % N;
    }
    return hash;
}


// Loads dictionary into memory, returning true if successful, else false
// bool load(const char *dictionary)
// {
//     // Assuming TABLE_SIZE is the size of your hash table
//     for (int i = 0; i < N; i++) {
//         table[i] = NULL;
//     }
//     FILE *dict = fopen(dictionary, "r");
//     if (dict == NULL) {
//         return false;
//     }

//     FILE *out = fopen("outcome.txt", "w");

//     char curr_word[LENGTH + 1];
//     unsigned int t_hash = 0;

//     while (fread(curr_word, LENGTH + 1 , 1, dict) == 1) {
//         // Ensure null termination
//         curr_word[LENGTH] = '\0';
//         t_hash = hash(curr_word);
//         node *new_word = malloc(sizeof(node));
//         if (new_word == NULL) {
//             // Error handling if malloc fails
//             return false;
//         }

//         // Safe copy using strncpy, limiting copied characters to LENGTH
//         strncpy(new_word->word, curr_word, LENGTH);
//         new_word->word[LENGTH] = '\0'; // Ensure null termination in new_word
//         new_word->next = NULL;

//         fwrite(new_word->word, LENGTH, 1, out);

//          // Assuming TABLE_SIZE is the size of your hash table
//         if (table[t_hash] != NULL) {
//             new_word->next = table[t_hash];
//         }
//         table[t_hash] = new_word;  // Assign new_word to the hash table
//         SIZE++;
//     }

//     // Check for errors during the last read
//     if (ferror(dict)) {
//         // Handle file read error
//         return false;
//     }

//     fclose(out);
//     fclose(dict);

//     return true;
// }

// Function to load the dictionary from a file
bool load(const char *dictionary) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~LOADING~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL) {
        printf("dict is NULL\n---------------------------------------------------\n");
        return false; // Handle file opening error
    }

  // Define the hash table (replace with desired size)
    for (int i = 0; i < N; i++) {
        table[i] = NULL;
    }


    size_t word_size;
    char word[LENGTH];
    while (fread(word, LENGTH+1, 1, dict)) {//fread(word, LENGTH, 1, dict)fgets(word, LENGTH, dict)
        if (strchr(word, '\n') == NULL) {
            printf("Warning: Line too long, exceeding maximum word length\n");
            continue;
        }
        printf("word before strcspan: %s", word);
        word_size = strcspn(word, "\n");
        for (int i = 0; word[i] != '\0'; i++) {
            // Check for newline character
            if (word[i] == '\n') {
                printf("\\n");
            } else {
                putchar(word[i]);
            }
        }
        // }
        printf("\n");
        printf("word_size: %zu\n", word_size);
        word[word_size] = '\0';
        // char ch;
        // printf("word after strcspan: %s\n", word);


        int index = hash(word);
        printf("Loading word: %s\n", word);
        // Allocate memory for a new node directly
        node *new_word = (node*)malloc(sizeof(node));
        if (new_word == NULL) {
            // Handle memory allocation error
            printf("new_word is NULL: %s at %u\n", word, index);
            printf("-----------------------------------------------\n");
            fclose(dict);
        return false;
        }

        strncpy(new_word->word, word, LENGTH - 1);
        new_word->word[LENGTH - 1] = '\0'; // Ensure null termination
        new_word->next = table[index];
        printf("Success\nnew_word->word: %s, new_word->next: %p\n", new_word->word, new_word->next);

        // Prepend the new node to the linked list
        table[index] = new_word;
        printf("table[index] address: %p\n", table[index]);
        printf("-----------------------------------------------\n");
        SIZE++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (SIZE > 0){
        return SIZE;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL) {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
    return true;
}
