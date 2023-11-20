#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/*
* simple_shell1 - first function
* Return: void
*/

void simple_shell1(void)
{
    char *str = NULL;
	size_t n = 0;
	ssize_t read;
	char *argv[] = {"", ".", NULL};
	pid_t child_p;
	int status, execReturn;

	printf("#cisfun$ ");
	while ((read = getline(&str, &n, stdin)) != -1)
	{
		str = strtok(str, "\n");
		child_p = fork();
		if (child_p == 0)
		{
			argv[0] = malloc(strlen(str) + 1);
			strcpy(argv[0], str);
			execReturn = execve(argv[0], argv, NULL);
			if (execReturn == -1)
			{
				printf("./shell: No such file or directory\n");
                    		exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("#cisfun$ ");
			wait(&status);
			free(str);
		}
	}
}
