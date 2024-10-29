/**
 * https://leetcode.com/problems/merge-strings-alternately/
 * 1768. Merge Strings Alternately
 * Difficulty: Easy
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2);

int main(void)
{
    char *w1 = "abc";
    char *w2 = "pqr123";
    char *result = mergeAlternately(w1, w2);
    printf("Result = %s\n", result);
    
    if (result) {
        free(result); // Free the allocated memory to avoid memory leak
        result = NULL; // Set to NULL to prevent accidental double free
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

char * mergeAlternately(char * word1, char * word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    char *result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failure
    }

    result[0] = '\0'; // Start with an empty string

    for (int i = 0, j = 0; i < len1 || i < len2; i++) {
        if (i < len1) {
            result[j++] = word1[i]; // Append one character from w1
        }
        if (i < len2) {
            result[j++] = word2[i]; // Append one character from w2
        }
    }
    return result; // Return the merged string
}
