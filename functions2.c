#include "main.h"
/**
 * _strncmp - Compare at most 'n' characters of two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer ..
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
		n--;
	}

	return (0);
}
/**
 * _atoi - Convert a string to an integer.
 * @str: Pointer to the input string.
 *
 * Return: The converted integer.
 */
int _atoi(const char *str)
{
	int sign = 1;
	int result = 0;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (result * sign);
}
/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @str: Pointer to the input string.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of 'c' in 'str',
 *         or NULL if 'c' is not found.
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	return ((*str == c) ? (char *)str : NULL);
}
/**
 * _strdup - Duplicate a string in a new memory location.
 * @str: Pointer to the input string to be duplicated.
 *
 * Return: A pointer to the new duplicated string,
 *         or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	size_t len;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	duplicate = malloc((len + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	_strcpy(duplicate, str);

	return (duplicate);
}
