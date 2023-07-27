#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[], char *envp[]);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **chstrtok(char *str);
char *filechk(char *str);
int pathchk(char *str);
void forkexe(char **arstr, char *envp[]);
int checkinbuilt(char *str);
char *_strcat(char *des, char *src);
int _strcmp(char *fi, char *sd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *filechk(char *str);

#endif
