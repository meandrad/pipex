# Pipex

The Pipex project implements a program that mimics the behavior of the shell's pipeline (`|`), allowing the output of one command to be used as the input of another.

## Project Files

- `pipex.c`: Main implementation of the pipex function.
- `pipex.h`: Header file containing function prototypes and necessary macros.
- `utils.c`: Utility functions for handling strings, memory, and file descriptors.
- `str_utils.c` and `ft_split.c`: Functions from libft.

## How It Works

Pipex takes two commands and redirects the output of the first command as input to the second command using pipes. The program processes files and executes commands similarly to the shell.

### Example:
```shell
./pipex infile "cmd1" "cmd2" outfile
```
Equivalent to:
```shell
< infile cmd1 | cmd2 > outfile
```

## How to Use

### Step 1: Clone the Repository
To get started, clone the repository using Git:
```shell
git clone https://github.com/meandrad/pipex.git
```

### Step 2: Compile the Code
Use `make` to compile the project:
```shell
make
```
This will generate an executable called `pipex`.

### Step 3: Run the Program
```shell
./pipex infile "ls -l" "wc -l" outfile
```
This command takes the content of `infile`, executes `ls -l`, passes the output to `wc -l`, and writes the result to `outfile`.

### Step 4: Run the Test
To check for memory leaks and errors, run:
```shell
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./pipex infile "cmd1" "cmd2" outfile
```


