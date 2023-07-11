#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr *header;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
exit(EXIT_FAILURE);
}

fd = open(argv[1], O_RDONLY);

if (fd == -1)
{
perror("open");
exit(EXIT_FAILURE);
}

header = malloc(sizeof(Elf64_Ehdr));

if (header == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
perror("read");
exit(EXIT_FAILURE);
}

check_elf(header->e_ident);

printf("ELF Header: ");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

close(fd);
free(header);

return 0;
}

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

void print_magic(unsigned char *e_ident)
{
int index;

printf("Magic: ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x ", e_ident[index]);
}

printf("\n");
}

void print_class(unsigned char *e_ident)
{
printf("Class: ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
break;
}
}

void print_data(unsigned char *e_ident)
{
printf("Data: ");

switch (e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_DATA]);
break;
}
}

void print_version(unsigned char *e_ident)
{
printf("Version: ");

switch (e_ident[EI_VERSION])
{
case EV_NONE:
printf("none\n");
break;
case EV_CURRENT:
printf("1 (current)\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_VERSION]);
break;
}
}

void print_abi(unsigned char *e_ident)
{
printf("OS/ABI: ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_AIX:
printf("UNIX - AIX\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_MODESTO:
printf("Novell - Modesto\n");
break;
case ELFOSABI_OPENBSD:
printf("UNIX - OpenBSD\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
break;
}
}

void print_osabi(unsigned char *e_ident)
{
printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2LSB)
e_type = ((unsigned char *)&e_type)[0] |
((unsigned char *)&e_type)[1] << 8 |
((unsigned char *)&e_type)[2] << 16 |
((unsigned char *)&e_type)[3] << 24;

printf("Type: ");

switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
break;
}
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2LSB)
e_entry = ((unsigned char *)&e_entry)[0] |
((unsigned char *)&e_entry)[1] << 8 |
((unsigned char *)&e_entry)[2] << 16 |
((unsigned char *)&e_entry)[3] << 24;

printf("Entry point address: %lx\n", e_entry);
}
