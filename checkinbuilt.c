#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * checkinbuilt - Funtion 2 chk if inbuilt command to execute  and skip fork
 * @str: string to chect for inbuilt command if present
 * Return: 1 if false and 0 if true
 */
int checkinbuilt(char *str)
{
	char **arr;
	int i = 0;
	char *username;

	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
		return (0);
	arr[0] = "cd";
	arr[1] = "exit";
	arr[2] = "hello";
	for (i = 0; i < 3; i++)
	{
		if (_strcmp(arr[i], str) == 0)
		{
			break;
		}
	}
	i++;
	switch (i)
	{
	case 1:
		chdir(str);
		free(arr);
		return (1);
	case 2:
		printf("bye");
		free(arr);
		return (2);
	case 3:
		username = getenv("HOSTNAME");
		printf("Hello %s\n", username);
		free(arr);
		return (1);
	default:
		free(arr);
		return (0);
	}
	return (0);
}
/**
 * builtin_exit - Exit the shell
 *
 * Return: 0 to exit the shell
 */
int builtin_exit(void)
	{
		return (0);
	}

/**
 * builtin_env - Print the environment variables
 *
 * @env: Environment variables
 *
 * Return: Always returns 1
 */
int builtin_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
	write(STDOUT_FILENO, env[i], _strlen(env[i]));
	write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}

