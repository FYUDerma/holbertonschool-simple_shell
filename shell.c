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
int main(int ac, char **av)
{
	char *prompt = "$ ";
	char *lineptr = NULL; /* Adresse du buffer de saisie */
	size_t n = 0; /* Taille allouée en octets */
	ssize_t nchars_read; /* Nombre de caractères lus */
	pid_t pid;
	int status; /* Statut de sortie */

	(void)ac;
	(void)av;

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
			exit(1); /* Arrète le programme avec un status d'erreur */
		}
		else if (pid == 0)
		{
			char *argv_exec[2]; /* tableau de pointeurs de char pour execve */
			argv_exec[0] = lineptr;
			argv_exec[1] = NULL;

			if (execve(argv_exec[0], argv_exec, NULL) == -1) /* Exécute la commande */
			{
				perror("Error");
				free(lineptr);
				exit(1); /* Arrète le programme avec un status d'erreur */
			}
		}
		else
			wait(&status);
	}

	free(lineptr);
	return (0);
}
