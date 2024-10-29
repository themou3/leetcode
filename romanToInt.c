/**
 * https://leetcode.com/problems/roman-to-integer/
 * 13. Roman to Integer
 * Difficulty: Easy
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int romanToInt(char* s);

int main(void)
{
    char* str = "LVIII";
    int result = romanToInt(str);
    printf("result = %i\n", result);
    return 0;
}

int romanToInt(char* s)
{
    int     arr[7] = {1, 5, 10, 50, 100, 500, 1000};
    char*   romanVocab = "IVXLCDM";
    int *   resultArr = malloc(strlen(s) * sizeof(int));
    int     newResultInt = 0;
    int     tempInt = 0;

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        for (int j = 0; j < strlen(romanVocab); j++)
        {
            if (s[i] == romanVocab[j])
            {
                resultArr[i] = arr[j];
                if (tempInt <= resultArr[i])
                {
                    tempInt = resultArr[i];
                    newResultInt += resultArr[i];
                }
                else if (tempInt > resultArr[i])
                {
                    tempInt = resultArr[i];
                    newResultInt -= resultArr[i];
                }
                break;
            }
        }
    }
    return newResultInt;
}
