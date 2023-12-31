#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

char *filechk(char *str)
{
	DIR *dir = opendir("/bin/");
	char *temp, *cats;
	struct dirent *entity;

	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
		temp = entity->d_name;
		if (_strcmp(temp, str) == 0)
		{
			cats = _strcat("/bin/", str);
			closedir(dir);
			return (cats);
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}

