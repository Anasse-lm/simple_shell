#include "shell.h"

/**
 * main - entry point
 * Return: 0.
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	int status = 0;
	char **tokLine = NULL;
	(void)ac;
	(void)av;
	(void)env;

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
