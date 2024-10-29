/**
 * https://leetcode.com/problems/is-subsequence/
 * 392. Is Subsequence
 * Difficulty: Easy
 */

#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t);

int main(void)
{
char * s = "abc";
char * t = "ahbgdc";
bool flag = isSubsequence(s, t);
printf("result = %s\n", flag ? "true" : "false");
}

bool isSubsequence(char* s, char* t)
{
    bool result = true;
    result = (t[0] == '\0' && s[0] != '\0') ? false : true;

    for (int i = 0, a = 0; t[i] != '\0' && s[a] != '\0'; i++)
    {
        if (t[i] == s[a])
        {
            result = true;
            printf("if: \tt = %c, s = %c\n", t[i], s[a]);
            a++;
        }
        if (s[a] != '\0' && t[i + 1] == '\0')
        {
            printf("i'm here\n");
            result = false;
        }
        else if (t[i] != s[a] && s[a] != '\0')
        {
            printf("else: \tt = %c, s = %c\n", t[i], s[a]);
            result = false;
        }
    }
    return result;
}
