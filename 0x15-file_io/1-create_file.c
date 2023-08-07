#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "main.h"

/**
* create_file - function that creates a file.
* @filename: variable pointer
* @text_content: content file
* Description: Create a function that creates a file.
* Return: 1 on success, -1 on failure
*/

int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t bytes_written;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
bytes_written = write(fd, text_content, strlen(text_content));
if (bytes_written == -1)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
