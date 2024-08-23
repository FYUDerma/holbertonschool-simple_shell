#include "main.h"

/**
 * main - main function for shell
 * Return: Always 0
 */

int main(void)
{
	int exitStatus = 1, exitCode;
	char *line = NULL, *input = NULL;
	size_t bufsize = 0;
	ssize_t string;

	while (1)
	{
		if (isatty(0))
		{
			printf("HBTN-Shell: ");
		}

		string = getline(&line, &bufsize, stdin);

		if (string == -1)
		{
			break;
		}

		input = trim(line);
		if (strncmp(input, "exit", 4) == 0)
		{
			free(line);

			if (sscanf(input, "exit %d", &exitCode) == 1)
			{
				exit(exitCode);
			}
			else
				exit(0);
		}
		exitStatus = execute(input);
		if (exitStatus == -1)
		{
			printf("%s: not found\n", input);
			continue;
		}
	}
	free(line);
	return (0);
}
