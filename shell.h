#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

#define BUFSIZE 1024

extern char **environ;

char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *p, unsigned int sz, unsigned int nsz);
char **split_str(char *str, char *del);
char *_getenv(char *env_var);
void signalhandler(int sigid);
int builtInexec (char** tokens, char *line);
char *concat (char* pname, char *cname);
char *find(char *cmd);
int execute (char  *cmd, char **tokens);
void free_array(char **array);

#endif
