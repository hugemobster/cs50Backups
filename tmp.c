#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned int dude(const char *word);

int main() {
    char input[] = "jackfruit"; // Example input
    // int index;

    // if(strlen(input) >= 2) {
    //     // Convert characters to zero-based index
    //     int firstChar = input[0] - 'a';
    //     int secondChar = input[1] - 'a';

    //     // Map to single integer between 0 and 675
    //     index = firstChar * 26 + secondChar;

    //     printf("Index: %d\n", index);
    // } else {
    //     printf("Input string must have at least two characters.\n");
    // }

    // typedef struct node
    // {
    //     char word[LENGTH + 1];
    //     struct node *next;
    // } node;
    // node *table[26];

    // if (table[0] == NULL){
    //     printf("null\n");
    // }
    // else{
    //     printf("%s\t %", );
    // }
    printf("%u\n", dude(input));

    return 0;
}

unsigned int dude(const char *word)
{
    int N = 45;
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (hash * 31 + tolower(word[i])) % N; // Assuming N is the table size
    }
    return hash;
}
