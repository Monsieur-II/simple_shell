#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

/*Macros*/
#define MAX_COMMAND_LEN 100
#define INITIAL_BUFFER_SIZE 120
#define MAX_ARGS 64

/*Non-intereactive*/
void non_int(char **argv, char *line_read, char **args,
		char *command_path, size_t n);

/*Built-in*/
int built_in(char **line_read, char **args);
void exit_shell(char **line_read);
void _env(char **line_read);

/**
 * struct builtin - builtin struct
 * @s: string of builtin name
 * @f: pointer to builtin function
 */

typedef struct builtin
{
	char *s;
	void (*f)(char **);
} blt;

/*getenv*/
extern char **environ;
char *_getenv(const char *name);

/*getline*/
ssize_t _getline(char **lineptr, size_t *n, int fd);


/*shell.c*/
void read_input(char **line_read, size_t *n);
char *find_command(char **args);
void execute_command(char *command_path, char **args);
void tokenize(char *str, char **args, int max_args, char *delimiters);

/*Error handling*/
void addCount(char *str, int num);
void p_error(char *argv, char *args, int count);
void handle_ctrl_c(int signal);

/*Memory*/
void _free(char **lineptr);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/*strings*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /*MAIN_HEADER*/
