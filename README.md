![Logo](https://media.licdn.com/dms/image/D5612AQFrMNx9-OrAIQ/article-cover_image-shrink_720_1280/0/1682905165497?e=1729728000&v=beta&t=9xYs6g415jwBvKJJCSBxw-f0OFMp247yD009vgxJM1c)


# **SIMPLE SHELL IN C LANGUAGE**


## **SYNOPSIS**
The shell is Linux's command-line interpreter. It provides an interface between the user and the kernel and executes programs called commands. For example, if a user enters ls, the shell executes the ls command.
## **LIST OF ALLOWED FUNCTIONS AND SYSTEM CALLS**

| Functions        | Man Pages      | Definitions |
| ------|-----|-----|
|access |man 2 access|Checks a user's permissions for a file.
chdir |man 2 chdir|changes the current working directory.
close |man 2 close|closes a file descriptor.
closedir |man 3 closedir|Closes a directory stream.
execve |man 2 execve|Executes a program.
exit |man 3 exit|Terminates a program normally.
_exit |man 2 _exit|Immediately terminates the calling process.
fflush |man 3 fflush|Flushes the output buffer of a stream.
fork |man 2 fork|Creates a new process by duplicating the calling process.
free |man 3 free|Frees memory previously allocated by `malloc`.
getcwd |man 3 getcwd|Gets the current working directory.
getline |man 3 getline|Reads an entire line from a stream.
getpid |man 2 getpid|Returns the process ID (PID) of the calling process.
isatty |man 3 isatty|Checks whether a file descriptor refers to a terminal.
kill |man 2 kill|Sends a signal to a process or process group.
malloc |man 3 malloc|Allocates memory.
open |man 2 open|Opens a file and returns a file descriptor.
opendir |(man 3 opendir|Opens a directory stream.
perror |man 3 perror|Prints a description of the last error that occurred.
printf |man 3 printf|Various functions for formatted output.
fprintf |man 3 fprintf|Various functions for formatted output.
vfprintf |man 3 vfprintf|Various functions for formatted output.
sprintf |man 3 sprintf|Various functions for formatted output.
putchar |man 3 putchar|Writes a character to standard output.
read |man 2 read|Reads from a file descriptor.
readdir |man 3 readdir|Reads a directory entry from a directory stream.
signal |man 2 signal|Sets a signal handler.
stat |__xstat) man 2 stat|Gets file status information.
lstat |__lxstat man 2 lstat|Gets file status information.
fstat |__fxstat man 2 fstat|Gets file status information.
strtok |man 3 strtok|Converts a string to tokens.
wait |man 2 wait|Waits for the process to terminate.
waitpid |man 2 waitpid|Waits for the process to terminate.
wait3 |man 2 wait3|Waits for the process to terminate.
wait4 |man 2 wait4|Waits for the process to terminate.
write |man 2 write|Writes to a file descriptor.

## **COMPILATION**
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## **Testing**
```
$ ./hsh
HBTN-Shell: /bin/ls
AUTHORS  README.md  func.c  hsh  main.c  main.h  man_1_simple_shell
HBTN-Shell: ls
AUTHORS  README.md  func.c  hsh  main.c  main.h  man_1_simple_shell
HBTN-Shell: exit
$
```

## **PATH ENVIRONMENT VARIABLE**

The PATH environment variable is an important security control. It specifies the directories to be searched to find a command. The default systemwide PATH value is specified in the /etc/profile file, and each user normally has a PATH value in the user's $HOME/.
## **PID  PPID**

- PID stands for Process ID, Which means Identification Number for currently running process in Memory.
- PPID stands for Parent Process ID, Which means Parent Process is the responsible for creating the current process(Child Process).
## **AUTHORS**

#### [Yanis MEFTOUH](https://github.com/yanis59100):
<8845@holbertonstudents.com>
#### [Zakaria AATTACHE](https://github.com/FYUDerma):
<9398@holbertonstudents.com>
