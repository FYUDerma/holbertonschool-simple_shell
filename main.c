#include "main.h"

/**
 * main - main function for shell
 * @argc: number of arguments
 * @argv: argument values
 * Return: Always 0
 */

int main(void)
{
	int exitStatus = 1, exitCode; /* declare 2 integere dont un avec la valeur 1*/
	char *line = NULL, *input = NULL; /* declare 2 string avec la valeur null*/
	size_t bufsize = 0; /* declare un entier positif de valeur 0*/
	ssize_t string; /* declare un entier positif*/

	while (1) /* bouble infini*/
	{
		if (isatty(0)) /* Si cette condition est vraie, cela signifie que l'entrée standard est bien un terminal*/
		{
			printf("HBTN-Shell: "); /* affiche hbtn-shell:*/
		}

		string = getline(&line, &bufsize, stdin); /**/

		if (string == -1)/* si string = -1*/
		{
			break; /* met fin a la boucle*/
		}

		input = trim(line); /* effeca les espaces*/

		if (strncmp(input, "exit", 4) == 0) /* compare les 4 premier caractere de input avec la chaine exit*/
		{
			free(line); /* met fin a l'allocation line*/

			if (sscanf(input, "exit %d", &exitCode) == 1) /* affiche exit 1*/
			{
				exit(exitCode); /* ferme la fonction faux*/
			}
			else /* sinon*/
				exit(0); /* ferme la fonction vrai*/
		}

		exitStatus = execute(input); /* exitstatus a pour valeur l'execution de input*/

		if (exitStatus == -1) /* si l'execution de input = -1*/
		{
			printf("%s: not found\n", input); /* affiche un string: not found*/
			continue;/* continue la boucle*/
		}
	}

	free(line); /* met fin a l'allocation line*/
	return (0); /* retourne un entier*/
}
