#include "shell.h"

/**
 * _strdup - to duplicate a string
 * @str: string to duplicate
 * Return: char*
*/

char *_strdup(char *str)
{
    int i = 0, len;
    char *ptr;

    if (str == NULL)
    {
        return (NULL);
    }
    while (str[i] != '\0')
    {
        i++;
    }
    len = i;
    ptr = (char *)malloc(sizeof(char) * len);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        ptr[i] = str[i];
        i++;
    }
    return (ptr);
}

/**
 * _strlen - strings lenght
 * @str: string
 * Return: int
*/

int _strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
