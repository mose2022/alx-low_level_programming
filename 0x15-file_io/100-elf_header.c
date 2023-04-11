#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void check_elf(unsigned char *pointer);
void print_class(unsigned char *pointer);
void print_data(unsigned char *pointer);
void print_magic(unsigned char *pointer);
void print_abi(unsigned char *pointer);
void print_version(unsigned char *pointer);
void print_osabi(unsigned char *pointer);
void print_entry(unsigned long int e_entry, unsigned char *pointer);
void print_type(unsigned int e_type, unsigned char *pointer);
void close_elf(int elf);

/**
 * check_elf - check if a file is ELF.
 * @pointer: A pointer to an array.
 * Description: If file note ELF - exit code 98.
 */
void check_elf(unsigned chr *pointer)
{
    int index;
    for (index = 0; index < 4; index++)
    {
        if (pointer[index] != 127 &&
            pointer[index] != 'E' &&
            pointer[index] != 'L' &&
            pointer[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * @print_magic - Prints the magic numbers of ELF
 * @pointer: A pointer to array
 * Description: Magic numbers separated by space.
 */
void print_magic(unsigned char *pointer)
{
    int index;
    printf("  Magic:   ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", pointer[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_class - Prints the class of ELF.
 * @pointer: A pointer to array.
 */
void print_class(unsigned char *pointer)
{
	printf("  Class:                             ");
	switch (pointer[EI_CLASS])
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
		printf("<unknown: %x>\n", pointer[EI_CLASS]);
	}
}

/**
 * print_data - Prints data of ELF.
 * @pointer: A pointer to array.
 */
void print_data(unsigned char *pointer)
{
	printf("  Data:  ");

	switch (pointer[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", pointer[EI_CLASS]);
	}
}

/**
 * print_version - prints the version of ELF.
 * @pointer: Apointer to array.
 */
void print_version(unsigned char *pointer)
{
	printf("  Version:   %d",
	       pointer[EI_VERSION]);

	switch (pointer[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of ELF.
 * @pointer: A pointer to array.
 */
void print_osabi(unsigned char *pointer)
{
	printf("  OS/ABI:                            ");

	switch (pointer[EI_OSABI])
	{
	case ELFOSABI_NONE:
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
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", pointer[EI_OSABI]);
	}
}

/**
 * print_abi - Prints ABI Version of ELF.
 * @pointer: A pointer to array.
 */
void print_abi(unsigned char *pointer)
{
	printf("  ABI Version:   %d\n",
	       pointer[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of ELF.
 * @e_type: the Elf type.
 * @pointer: a pointer to array.
 */
void print_type(unsigned int e_type, unsigned char *pointer)
{
	if (pointer[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

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
	}
}

/**
 * print_entry - prints the entry point of ELF.
 * @e_entry: the address of ELF.
 * @pointer: a pointer to array.
 */
void print_entry(unsigned long int e_entry, unsigned char *pointer)
{
	printf("  Entry point address:               ");

	if (pointer[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (pointer[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elfile: The file descriptor of the ELF file.
 * Description: If file can't close - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - display the information.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: On success, 0.
 * Description: If file not ELF - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *head;
    int k, m;

    k = open(argv[1], O_RDONLY);
    if (k == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    head = malloc(sizeof(Elf64_Ehdr));
    if (head == NULL)
    {
        close_elf(k);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    m = read(k, head, sizeof(Elf64_Ehdr));
    if (m == -1)
    {
        free(head);
        close_elf(k);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    check_elf(head->e_ident);
    printf("ELF Header:\n");
    print_magic(head->e_ident);
    print_class(head->e_ident);
    print_data(head->e_ident);
    print_version(head->e_ident);
    print_osabi(head->e_ident);
    print_abi(head->e_ident);
    print_type(head->e_type, head->e_ident);
    print_entry(head->e_entry, head->e_ident);

    free(head);
    close_elf(k);
    return (0);
}
