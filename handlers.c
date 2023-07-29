#include "main.h"
/**
 * _getenv - Get the value of an environment variable.
 * @name: Pointer to the name of the environment variable.
 *
 * Return: A pointer to the value of the environment variable.
 *         If the variable is not found, returns NULL.
 */
char *_getenv(const char *name)
{
	if (name == NULL || *name == '\0')
		return (NULL);

	extern char **environ;
	size_t name_len = _strlen(name);

	for (int i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (environ[i] + name_len + 1);
	}

	return (NULL);
}
/**
 *_fputc - Writes a single character to a stream
 *@c: The character to be written
 *@stream: The stream to which the character should be written.
 *Return: The number of characters written, or EOF on error.
 */
int _fputc(int c, FILE *stream)
{
	char buf[1];

	buf[0] = c;

	return (fwrite(buf, 1, 1, stream));
}
/**
 * _fputs - Custom implementation of fputs function
 * @str: String to be printed
 * @stream: Pointer to the output stream
 * Return: Number of characters printed
 */
int _fputs(const char *str, FILE *stream)
{
	if (str == NULL || stream == NULL)
		return (-1);

	int count = 0;

	while (*str != '\0')
	{
		if (fputc(*str, stream) == EOF)
			return (-1);
		str++;
		count++;
	}

	return (count);
}
/**
 * _puts - Custom implementation of puts function
 * @str: String to be printed
 * Return: Number of characters printed
 */
int _puts(char *str)
{
	int i, count = 0;

	if (str == NULL)
	return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
	_putchar(str[i]);
	count++;
	}

	return (count);
}


