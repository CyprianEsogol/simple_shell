#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define MAX_COMMAND_LEN 1024
#define MAX_TOKENS 64
#define DELIMITER " \t\n"

#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>

extern char **environ;

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
int _putchar(char c);
size_t _strlen(const char *s);
void free_args(char **args);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcpy(char *destination, const char *source);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(const char *str);
char *_strdup(const char *str);
char *_strchr(const char *str, int c);
void free_tokens(char **tokens);
char **parse_command(char *command);
int _fputs(const char *str, FILE *stream);
char *_getenv(const char *name);
int _puts(char *str);
int _fputc(int c, FILE *stream);
char **split_line(char *line);
int handle_semicolon(char *line);
int builtin_exit(void);
int builtin_env(char **env);
int execute(char **args);
int execute_exit(char **args);
int execute_env(void);
int execute_command(char **args);
#endif

