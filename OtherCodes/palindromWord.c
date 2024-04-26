#include <stdio.h>
#include <string.h>

int isPalindrom(char word[])
{
    int lenght = strlen(word);
    for (int i = 0; i < lenght / 2; i++)
    {
        if (word[i] != word[lenght - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char word[100];
    printf("Enter the word to check palindrom\n");
    scanf("%s", word);
    if (isPalindrom(word))
    {
        printf("The word is palindrom\n");
    }
    else
    {
        printf("The word is not palindrom\n");
    }
    return 0;
}