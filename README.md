# Simple Shell Project

A simple shell group project done by [@Monsieur-II](https://github.com/Monsieur-II) and [@Jennie547](https://github.com/Jennie547).

## Synopsis

This is a simple implementation of a UNIX command interpreter.
Not a perfect shell but is able to execute basic commands(ls, cat, cp, mv, echo etc...).

## Description

The shell is able to interpret and execute command line arguments from the user through the Standard input. It reads a given line, breaks it into separate arguments and executes accordingly. This shell behaves like the `/bin/sh` shell in terms of output.

## Usage

All files are compiled on Ubuntu 20.04 LTS using:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

-   The shell works in both interactive and non-interactive modes.

-   Handles shell variable replacement (including the `$?` and `$$` variables).

-   The shell is able to take a file as input.
    -   Usage: `hsh [filename]`

## Built-Ins

The following built-ins are implemented:

-   `exit` `[status]` - Exits the shell with an exit status of `status`.
-   `env` - Prints the current environment.

## List of allowed functions and system calls

-   access (man 2 access)
-   chdir (man 2 chdir)
-   close (man 2 close)
-   closedir (man 3 closedir)
-   execve (man 2 execve)
-   exit (man 3 exit)
-   \_exit (man 2 \_exit)
-   fflush (man 3 fflush)
-   fork (man 2 fork)
-   free (man 3 free)
-   getcwd (man 3 getcwd)
-   getline (man 3 getline)
-   getpid (man 2 getpid)
-   isatty (man 3 isatty)
-   kill (man 2 kill)
-   malloc (man 3 malloc)
-   open (man 2 open)
-   opendir (man 3 opendir)
-   perror (man 3 perror)
-   read (man 2 read)
-   readdir (man 3 readdir)
-   signal (man 2 signal)
-   stat (\_\_xstat) (man 2 stat)
-   lstat (\_\_lxstat) (man 2 lstat)
-   fstat (\_\_fxstat) (man 2 fstat)
-   strtok (man 3 strtok)
-   wait (man 2 wait)
-   waitpid (man 2 waitpid)
-   wait3 (man 2 wait3)
-   wait4 (man 2 wait4)
-   write (man 2 write)
