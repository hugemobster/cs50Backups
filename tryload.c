#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

int LENGTH = 45;

// Represents a node in a hash table
typedef struct node
{
    char word[46];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

char u_word[45];

unsigned int SIZE = 0;

int main(void){
    char dictPath[] = "dictionaries/small";
    char filePath[] = "texts/cat.txt";

    FILE *dict = fopen(dictPath, "r");
    if (dict == NULL) {
        puts("error in dict loading");
        return 1;
    }

    int word_size;

    char word[LENGTH + 1];
    char temp;
    while(fread(word, LENGTH, 1, dict) == 0){
        word_size = strcspn(word, "\n");
        word[word_size] = '\0';
        printf("%s ", word);
    }




}
