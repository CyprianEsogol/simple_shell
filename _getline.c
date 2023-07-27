#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _getline - Print "$ " first with the string after it on next line
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 * @stream: The stream to receive file;
 * Return: length of input string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char str;
	int len = 120, *lenptr = &len;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error! wrong parameter or file pointer problem");
		exit(1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char) * len);
		if (*lineptr == NULL)
		{
			perror("Unable to allocate memory");
			exit(1);
		}
	}
	else
		*lineptr = realloc(*lineptr, *lenptr);
	while (fgets(*lineptr, *lenptr, stream))
	{
		if ((*n - strlen(*lineptr)) < sizeof(str))
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				perror("Unable to reallocate memory");
				exit(1);
			}
		}
		strcat(*lineptr, &str);
		if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
			return (strlen(*lineptr));
	}
	return (0);
}
