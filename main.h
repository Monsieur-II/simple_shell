#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

/*Macros*/
#define MAX_COMMAND_LEN 100
#define INITIAL_BUFFER_SIZE 120
#define MAX_ARGS 64

/*Non-intereactive*/
void non_int(char **argv, char *line_read, char **args,
			 char *command_path, size_t n);

/**Read _file*/

void read_file(char **argv, char *line_read, char **args,
			   char *command_path, size_t n);

/*Built-in*/
int built_in(char **line_read, char **args,
			 char **argv, int *status, int counter);
void exit_shell(char **line_read, char **args,
				char **argv, int *status, int counter);
void _env(char **line_read, char **args,
		  char **argv, int *status, int counter);
int check_digit(char *s);

/**
 * struct builtin - builtin struct
 * @s: string of builtin name
 * @f: pointer to builtin function
 */

typedef struct builtin
{
	char *s;
	void (*f)(char **, char **, char **, int *, int);
} blt;

/*getenv*/
extern char **environ;
char *_getenv(const char *name);

/*getline*/
ssize_t _getline(char **lineptr, size_t *n, int fd);

/*shell.c*/
void read_input(char **line_read, size_t *n);
void handle_dollar(char **args, int status, char *str);
char *find_command(char **args);
int execute_command(char *command_path, char **args);
void tokenize(char *str, char **args, int max_args, char *delimiters);
void handle_comment(char *s);

/*Error handling*/
void addCount(char *str, int num);
void p_error(char *argv, char *args, int count);
void handle_ctrl_c(int signal);
void exit_error(char *argv, char **args, int count);
void file_error(char **argv, int counter);

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
int _atoi(char *s);
char *_memset(char *s, char b, unsigned int n);

#endif /*MAIN_HEADER*/
