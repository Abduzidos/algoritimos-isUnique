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
    unsigned long character;
    char map[MAX_CHARS] = {0};

    // Ad Hoc Jumps
    if (lenght < 2)
        return TRUE;
    if (lenght > MAX_CHARS)
        return FALSE;

    for (character = 0; character < lenght; character++)
    {
        map[input[character]]++;
        if (map[input[character]] > 1)
            return FALSE;
    }
    return TRUE;
}