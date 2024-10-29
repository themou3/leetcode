/**
 * https://leetcode.com/problems/longest-common-prefix/
 * 14. Longest Common Prefix
 * Difficulty: Easy
 */

#include <stdio.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main(int argc, char *argv[])
{
    // char *strs[] = {"flower", "flow", "flight"};
    char str1[] = "flower";
    char str2[] = "flow";
    char str3[] = "flight";
    char *strs[] = {str1, str2, str3};

    int strsSize = sizeof(strs) / sizeof(strs[0]);
    char *result = longestCommonPrefix(strs, strsSize);
    printf("Array size = %i\n", strsSize);
    printf("Longest Common Prefix: %s\n", result);

    return 0;
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0) return "";

    char *prefix = strs[0];
    int prefixLength = strlen(prefix);

    for (int i = 1; i < strsSize; i++)
    {
        int j = 0;

        while (j < prefixLength && j < strlen(strs[i]) && prefix[j] == strs[i][j])
        {
            j++;
        }
        prefixLength = j;

        if (prefixLength == 0)
            return "";
    }
    prefix[prefixLength] = '\0';
    return prefix;
}
