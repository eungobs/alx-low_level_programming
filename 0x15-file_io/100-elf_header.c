#include"main.h"

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
    e_ident[index] != 'E' &&
    e_ident[index] != 'L' &&
    e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file ");
exit(98);
}
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
int index;

printf("  Magic:   ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf(" ");
else
printf(" ");
}
}

/**
* print_class - prints the class of the ELF file
*
* @e_ident: a pointer to an array of bytes specifies
* how to interpret the file
*
* Return: nothing
*/
void print_class(unsigned char *e_ident)
{
printf(" class:                             ");

switch (e_ident[EI_CLASS]) /*EI_CLASS - File class*/
{
case ELFCLASSNONE:
printf("none ");
break;
case ELFCLASS32:
printf("ELF32 ");
break;
case ELFCLASS64:
printf("ELF64 ");
break;
default:
printf("<unknown: %x> ", e_ident[EI_CLASS]);
}
}

/**
* print_data - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *e_ident)
{
printf("  Data:                              ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none ");
break;
case ELFDATA2LSB:
printf("2's complement, little endian ");
break;
case ELFDATA2MSB:
printf("2's complement, big endian ");
break;
default:
printf("<unknown: %x> ", e_ident[EI_DATA]);
}
}

/**
* print_version - print the version of the ELF file
*
* @e_ident: a pointer to an array of bytes specifies
*           how to interpret the file
*
* Return: nothing
*/
void print_version(unsigned char *e_ident)
{
printf("  Version:                           ");/*EI_VERSION - File version*/

if (e_ident[EI_VERSION] == EV_CURRENT)
printf("%d (current) ", e_ident[EI_VERSION]);
else
printf("%i ", e_ident[EI_VERSION]);
}

/**
* print_osabi - prints the OS/ABI of the ELF file
*
* @e_ident: a pointer to an array of bytes specifies
*           how to interpret the file
*
* Return: nothing
*/
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");

switch (e_ident[EI_OSABI])/*EI_OSABI = OS Application Binary Interface*/
{
case ELFOSABI_SYSV:
printf("UNIX - System V ");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX ");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD ");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux ");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris ");
break;
case ELFOSABI_AIX:
printf("UNIX - AIX ");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX ");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD ");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64 ");
break;
case ELFOSABI_ARM:
printf("ARM ");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App ");
break;
default:
printf("<unknown: %x> ", e_ident[EI_OSABI]);
}
}

/**
* print_abi - Prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF ABI version.
*/
void print_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d ",
       e_ident[EI_ABIVERSION]);
}

/**
* print_type - prints the type of the ELF file
*
* @e_type: the object file type
* @e_ident: a pointer to an array of bytes specifies
*           how to interpret the file
*
* Return: nothing
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf("  Type:                              ");

switch (e_type)
{
case ET_NONE:
printf("NONE (Unknown type) ");
break;
case ET_REL:
printf("REL (Relocatable file) ");
break;
case ET_EXEC:
printf("EXEC (Exexutable file) ");
break;
case ET_DYN:
printf("DYN (Shared object file) ");
break;
case ET_CORE:
printf("CORE (Core file) ");
break;
default:
printf("<unknown: %x ", e_type);
}
}

/**
* print_entry - Prints the entry point of an ELF header.
* @e_entry: The address of the ELF entry point.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
  ((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x ", (unsigned int)e_entry);

else
printf("%#lx ", e_entry);
}

/**
* close_file - closes the ELF file
*
* @elf_file: the file descriptor for the ELF file
*
* Return: nothing
*/
void close_file(int elf_file)
{
if (close(elf_file) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d ", elf_file);
exit(98);
}
}


/**
* main - Entry point
*
* Description: elf_header_parser file
*
* @argc: argument counter
* @argv: argument vector
*
* Return: Always 0 (success)
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *head;
int head_file, read_file;

head_file = open(argv[1], O_RDONLY);
if (head_file == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s ", argv[1]);
exit(98);
}

head = malloc(sizeof(Elf64_Ehdr));
if (head == NULL)
{
close_file(head_file);
dprintf(STDERR_FILENO, "Error: Can't read file %s ", argv[1]);
exit(98);
}

read_file = read(head_file, head, sizeof(Elf64_Ehdr));
if (read_file == -1)
{
free(head);
close_file(head_file);
dprintf(STDERR_FILENO, "Error: `%s`: No such file ", argv[1]);
exit(98);
}
check_elf(head->e_ident);
printf("ELF Header: ");
print_magic(head->e_ident);
print_class(head->e_ident);
print_data(head->e_ident);
print_version(head->e_ident);
print_osabi(head->e_ident);
print_abi(head->e_ident);
print_type(head->e_type, head->e_ident);
print_entry(head->e_entry, head->e_ident);

free(head);
close_file(head_file);
return (0);
}
