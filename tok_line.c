#include "shell.h"

/**
 * tok_line - strtok a line
 * @line: string
 * Return: char **
 */

char **tok_line(char *line)
{
    char *str = _strdup(line);
    char *portion;
    int size = 0;
    char **result = NULL;
    int i = 0;
    if (str == NULL) {
        printf("str is null\n");
        return (NULL);
    }
    portion = strtok(str, " \t\n");
    while (portion)
    {
        size++;
        portion = strtok(NULL, " \t\n");
    }
    free(str);
    result = (char **)malloc(sizeof(char*) * (size + 1));
    portion = strtok(line, " \t\n");
    while (portion)
    {
        result[i] = portion;
        portion = strtok(NULL, " \t\n");
        i++;
    }
    result[i] = NULL;
    return result;
}
