my README FILE

Resources
Read or watch:

File descriptors
C Programming in Linux Tutorial #024 - open() read() write() Functions
man or help:

open
close
read
write
dprintf
Learning Objectives

General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
The only C standard library functions allowed are malloc, free and exit. Any use of functions like printf, puts, calloc, realloc etc… is forbidden
Allowed syscalls: read, write, open, close
You are allowed to use _putchar
You don’t have to push _putchar.c, we will use our file. If you do it won’t be taken into account
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples


Tasks
0. Tread lightly, she is near
mandatory
Write a function that reads a text file and prints it to the POSIX standard output.

Prototype: ssize_t read_textfile(const char *filename, size_t letters);
where letters is the number of letters it should read and print
returns the actual number of letters it could read and print
if the file can not be opened or read, return 0

  
1. Under the snow
mandatory
Create a function that creates a file.

Prototype: int create_file(const char *filename, char *text_content);
where filename is the name of the file to create and text_content is a NULL terminated string to write to the file
Returns: 1 on success, -1 on failure (file can not be created.

  
2. Speak gently, she can hear
mandatory
Write a function that appends text at the end of a file.

Prototype: int append_text_to_file(const char *filename, char *text_content);
where filename is the name of the file and text_content is the NULL terminated string to add at the end of the file
Return: 1 on success and -1 on failure
Do not create the file if it does not exist
If filename is NULL.


3. cp
mandatory
Write a program that copies the content of a file to another file.
   
4. elf
Write a program that displays the information contained in the ELF header at the start of an ELF file.

AUTHOR:EE NDZUKULE
