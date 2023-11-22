#include "shell.h"

/**
 * _executeCommand - executes a hsh command
 * @command: char ** of strings
 * Return: void
*/

void _executeCommand(char **command, int status)
{
    pid_t child_prosses;
    char message[] = "./shell: No such file or directory\n";

    child_prosses = fork();
    if (child_prosses == 0)
    {
        status = execve(command[0], command, NULL);
        if (status == -1)
        {
            write(STDOUT_FILENO, message, _strlen(message));
        }
        exit(status);
    }
    else
    {
        wait(&status);
    }
}
