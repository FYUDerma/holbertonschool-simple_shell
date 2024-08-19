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
	char *lineptr = NULL; /* Adresse du buffer de saisie */
	size_t n = 0; /* Taille allouée en octets */
	ssize_t nchars_read; /* Nombre de caractères lus */
	pid_t pid;
	int status; /* Statut de sortie */

	while (1) /* Boucle infinie pour lire et exécuter des commandes */
	{
		printf("%s", prompt); /* Affiche l'invite de commande */
		nchars_read = getline(&lineptr, &n, stdin); /* Lit une ligne de l'entrée standard */
		if (nchars_read == -1) /* Fin de fichier (CTRL + D) */
		{
			printf("\n");
			free(lineptr);
			return (0);
		}
		lineptr[strcspn(lineptr, "\n")] = 0; /* Supprime le saut de ligne de la saisie */

		pid = fork(); /* Crée un nouveau processus */
		if (pid == -1) /* Échec de la création du processus */
		{
			perror("fork");
			free(lineptr);
			exit(EXIT_FAILURE); /* Arrète le programme avec un status d'erreur */
		}
		else if (pid == 0) /* Processus fils */
		{
			char *argv[] = {lineptr, NULL};

			if (execve(argv[0], argv, NULL) == -1) /* Exécute la commande */
			{
				perror("Error");
				free(lineptr);
				exit(EXIT_FAILURE); /* Arrète le programme avec un status d'erreur */
			}
		}
		else /* Processus père */
			wait(&status); /* Attend la fin du processus fils */
	}

	free(lineptr);
	return (0);
}
