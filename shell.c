#include "shell.h"

/**
 * main - entry point
 * Return: 0.
 */
int main(void)
{
	char *line = NULL;
	int status = 0;
	char **tokLine = NULL;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			write(1, "\n", 1);
			return (status);
		}
		tokLine = tok_line(line);
		_executeCommand(tokLine, status);
    	free(line);
		free(tokLine);
	}
	return (0);
}
