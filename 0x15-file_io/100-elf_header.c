#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <errno.h>
#include <string.h>

#define ELF_MAGIC "\177ELF"

void print_error(char *message) 
{
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header) 
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) 
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "unknown");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "unknown");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
    printf("  Entry point address:               %lx\n", header->e_entry);
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }
    
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error opening file");
    }
    
    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) 
    {
        print_error("Error reading ELF header");
    }
    
    if (memcmp(header.e_ident, ELF_MAGIC, strlen(ELF_MAGIC)) != 0) 
    {
        fprintf(stderr, "%s is not an ELF file\n", argv[1]);
        exit(98);
    }
    
    print_elf_header(&header);
    
    close(fd);
    
    return 0;
}
