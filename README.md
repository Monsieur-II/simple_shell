The Simple Shell, an elegant UNIX command language interpreter, is a marvel of C implementation. With its ability to read commands from either a file or standard input, it offers a seamless user experience.

To ensure the highest standards of excellence, our team has compiled all files on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89. Our files are formatted with care to meet the Betty style, and all header files are include guarded.

Our shell is designed to be sophisticated yet intuitive, taking the user through the process with ease. The child process created to investigate the command is meticulous in its search for built-ins, aliases in the PATH, and local executable programs.

The command itself, accepting arguments with grace, will replace the child process, and when it completes its task, the program shall return to the parent process and print the prompt. This flawless feature allows the program to be enhanced and used repeatedly.

With the Simple Shell, every command is given the attention, honor, and respect it deserves. Even the non-interactive mode works seamlessly, and exiting the shell itself is elegantly designed. Pressing Ctrl-D or entering "exit" with or without a status will exit the program correctly.
