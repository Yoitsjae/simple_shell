#include "shell.h"

/**
 * split_str - splits a strimg into tokens
 * @str: strimg to be split
 * @del: delimiters
 * Return: pointer to an array of tokens
 */

char **split_str(char *str, char *del)
{
	char *token;
	char **result;
	int pos = 0;


	str = _strdup(str);
	token = strtok(str, del);
	result = malloc(BUFSIZE * sizeof(char *));

	if (!result)
		puts("error");
	while (token != NULL)
	{
		result[pos] = token;
		pos++;
		token = strtok(NULL, del);
	}
	result[pos] = NULL;
	return (result);
}

/**
 * _realloc - reallocates memory
 * @p: pointer to be reallocated
 * @sz: old size
 * @nsz: new size
 * Return: pointer to nee memory size
 */

void *_realloc(void *p, unsigned int sz, unsigned int nsz)
{
	unsigned int i = 0;
	char *np;

	if (sz == nsz)
		return (p);
	if (p == NULL)
	{
		np = malloc(nsz);
		if (np == NULL)
			return (NULL);
		return (np);
	}
	else
	{
		if (nsz == 0)
		{
			free(p);
			return (NULL);
		}
	}

	np = malloc(nsz);
	if (np == NULL)
		return (NULL);
	while (i < sz && i < nsz)
	{
		np[i] = ((char *)p)[i];
		i++;
	}
	free(p);
	return (np);
}

/**
 * free_array - frees a 2d array
 * @tokens: array to be freed
 * Return: void
 */

void free_array(char **tokens)
{
	char **temp = tokens;

	if (tokens)
	{
		while (*tokens)
		{
			free(*tokens);
			tokens++;
		}
		free(temp);
	}
}
