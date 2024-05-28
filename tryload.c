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
    char word[LENGTH];
    char temp;
    fread(word, LENGTH, 1, dict);

    for(int i = 0; i < strlen(word); i++){
        temp = word[i];
        if (temp == '\n'){
            printf("n");
        }

        else{
            printf("%c",word[i]);
        }


    }


}
