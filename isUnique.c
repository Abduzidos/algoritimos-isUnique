#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ASCII_TABLE 256
#define MAX_UTF8_TABLE 192

#define FALSE 0
#define TRUE 1

#define MAX_CHARS MAX_ASCII_TABLE

#define INPUT "ABCDEFGHIJKLMNOPQRSTUVXZ"

int isUnique(char *input);

int main()
{
    int initialTime = time(NULL);
    if (isUnique(INPUT))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    printf("The total run time was %d seconds", (int)(initialTime - time(NULL)));
    return 0;
}

int isUnique(char *input)
{
    size_t lenght = strlen(input);
    char head, test;

    // Ad Hoc Jumps
    if (lenght < 2)
        return TRUE;
    if (lenght > MAX_CHARS)
        return FALSE;

    for (head = 0; head < lenght - 1; head++)
    {
        for (test = head + 1; test < lenght; test++)
        {
            if (input[head] == input[test])
                return FALSE;
        }
    }
    return TRUE;
}