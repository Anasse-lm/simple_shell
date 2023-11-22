#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t read;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);

    read = getline(&line, &n, stdin);
    if (read <= 0)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
