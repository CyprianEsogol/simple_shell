#include "main.h"

/**
 * _putchar - Write a character to the standard output (stdout).
 * @c: The character to be written.
 *
 * Return: On success, returns the number of characters written.
 *         On error, returns -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strlen - Calculate the length of a null-terminated string.
 * @s: Pointer to the input string.
 *
 * Return: The length of the string as a size_t value.
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
/**
 * free_args - Free memory allocated for an array of strings.
 * @args: Double pointer to the array of strings to be freed.
 *
 * This function frees each individual string in the array
 * and then frees the array itself.
 */
void free_args(char **args)
{
	if (args == NULL)
		return;

	for (int i = 0; args[i] != NULL; i++)
		free(args[i]);

	free(args);
}
/**
 * _strcpy - Copy a null-terminated string from source to destination.
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 *
 * Return: A pointer to the destination string 'destination'.
 */
char *_strcpy(char *destination, const char *source)
{
	char *start = destination;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return (start);
}
/**
 * _strncpy - Copy at most 'n' characters from the source string
 * to the destination.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination string 'dest'.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
