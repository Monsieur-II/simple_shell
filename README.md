# Simple Shell Project
A simple shell group project done by [@Monsieur-II](https://github.com/Monsieur-II) and [@RaphaelSnR](https://github.com/RaphaelSnR)

## Synopsis
This is a simple implementation of a UNIX command interpreter

## Description
The shell is able to interpret and execute command line arguments from the user through the Standard input. It reads a given line, breaks it into separate arguments and executes accordingly. This shell behaves like the `/bin/sh` shell in terms of output.

## Usage
All files are compiled on Ubuntu 20.04 LTS using:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

* The shell works in both interactive and non-interactive modes

## Built-Ins
The following built-ins are implemented:
* `exit` - Exits the shell with an exit status of 0.
* `env` - Prints the current environment

