#include "main.h"

/**
 * _isspace - check if character is a space
 * @c: character to check
 * Return: 1 if true, 0 if false
 */

int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f') /* si la variable c = charactere
	d'espacement*/
	{
		return (1); /* retourne vrai*/
	}
	return (0); /* met fin a la fonction avec un entier*/
}

/**
 * trim - removes leading and trailing whitespace from string
 * @str: string to trim
 * Return: trimmed string
 */
char *trim(char *str)
{
	char *end = str + strlen(str) - 1; /* declare un string end qui a comme valeur str + la longueur - 1 */

	while (_isspace(*str)) /* boucle avec condition tant qu'un charactere d'espacement n'est pas trouver dans str*/
	{
		str++; /* incrementation de str*/
	}

	if (*str == 0) /* si le pointeur str est vide*/
		return (str); /* retourne*/

	while (end > str && _isspace(*end)) /* boucle tant que end est plus grand que str et qu'il y a une
	fontion d'espacement dans le pointeur end*/
	{
		end--; /* décrementation end*/
	}

	end[1] = '\0'; /* declare que la 2e ligne du tableau end est EOF*/

	return (str); /* met fin a la fonction avec un string*/
}

/**
 * tokenize - tokenizes a string
 * @input: string to tokenize
 * Return: tokenisez string
 */

char **tokenize(char *input)
{
    char **tokens = malloc(64 * sizeof(char *)); /* déclare un pointeur dans un pointeur qui a comme
	valeur une allocation de 64 * la taille d'un string*/
    char *token; /* déclare un un string */
    int i = 0; /* declare une variable de type integere de nom i et valeur 0*/

    if (!tokens) /* si token n'est pas null*/
    {
        fprintf(stderr, "$: allocation error\n"); /* affiche le prompt avec le message*/
        exit(EXIT_FAILURE); /* quitte le fichier*/
    }
    token = strtok(input, " \t\r\n\a"); /* prend le 1er token*/

    while (token != NULL) /* boucle avec condition tans que token n'est pas ou egal a null*/
    {
        tokens[i] = token; /* le string  de la ligne i a comme valeur token*/
        i++; /* incrementation de la variable */

        token = strtok(NULL, " \t\r\n\a"); /* prend le 2e tokens*/
    }

    tokens[i] = NULL; /* le i dans le tableau a comme valeur null*/
    return (tokens); /* met fin a la fonction avec un pointeur de poiteur de type char*/
}

/**
 * getPath - gets the path of a command
 * @input: command to get path of
 * Return: path of command
*/

char *getPath(char *input)
{
    char *result, *pathEnv, *pathEnvCopy, *token, fullPath[1024]; /* declare plusieurs string, le tableau
	fullparth a le maximum de octets*/

    pathEnv = getenv("PATH"); /* declare une variable d'environnement PATH*/

    if (pathEnv == NULL) /* si la variable de déclaration est null*/
    {
        return (NULL); /* retourne null*/
    }
    pathEnvCopy = strdup(pathEnv); /* */

    token = strtok(pathEnvCopy, ":"); /* */

    while (token) /* boucle tant que token est null*/
    {
        sprintf(fullPath, "%s/%s", token, input); /* affiche 2 string*/

        if (acces(fullPath, F_OK | X_OK) == 0)
        {
            result = strdup(fullPath); /* */
            free(pathEnvCopy); /* met fin a l'allocation de la variable d'environnement*/
            return (result); /* retourne result*/
        }

        token = strtok(NULL, ":"); /* */
    }

    free(pathEnvCopy); /* met fin a l'allocation*/
    return (NULL); /* retourn null*/
}

/**
 * execute - executes a command
 * @input: arguments to execute
 * Return: exit status
*/

int execute(char *input)
{
    int status, exitStatus = 0; /* declare 2 integere de valeur 0*/
    char **args, *path;/* declare un pointeur dans un pointeur et un string*/
    pid_t pid; /* declare un identifiant de processeur*/

    args = tokenize(input); /* creer un nouveau token*/
    if (args == NULL) /* si args est null*/
    {
        free(args); /* met fin l'allocation args*/
        return (1); /* retourn faux*/
    }

    if (input[0] == '/' || input[0] == '.')
        path = strdup(input);
    else
        path = getPath(args[0]);
    }

    if (path == NULL) /* si path est null*/
    {
        free(args); /* met fin a l'allocation args*/
        return (-1); /* retourn faux*/
    }

    pid = fork(); /* creer un enfant pid*/

    if (pid < 0) /* si pid est plus petit que null*/
    {
        free(args); /* met fin a l'allocation args*/
        free(path); /* met fin a l'allocation path*/
        return (-1); /* retourn faux*/
    }
    else if (pid == 0) /* aussi non si pid est null*/
    {
        exitStatus = execve(path, args, environ); /* donne la valeur d'execution */
    }
    else /* sinon*/
    {
        exitStatus = wait(&status); /* execute le programme	*/
        free(args); /* met fin a l'allocation args*/
        free(path); /* met fin a l'allocation path*/
    }

    return (exitStatus); /* retourn un entier*/
}
