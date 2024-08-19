#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Implementation of a UNIX command line interpreter.
 * Return:  0 on success, 1 on failure.
 */
int main(void)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	pid_t pid;
	int status;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("\n");
			free(lineptr);
			return 0;
		}
		lineptr[strcspn(lineptr, "\n")] = 0;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(lineptr);
			exit(1);
		}
		else if (pid == 0)
		{
			char *argv[] = {lineptr, NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				free(lineptr);
				exit(1);
			}
		}
		else
			wait(&status);
	}

	free(lineptr);
	return (0);
}
