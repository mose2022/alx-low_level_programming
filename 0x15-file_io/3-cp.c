#include "main.h"

/**
 * not-close - Prints the error.
 * @fd: The value to print.
 */
void not_close(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
	exit(100);
}

/**
 * cp - Copy the file.
 * @from: The file to copy.
 * @to: The file to copy in the details.
 */
void cp(char *from, char *to)
{
	int file_n, file_k, n, k;
	char buff[1024];

	file_n = open(from, O_RDONLY);
	if (file_n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
		exit(98);
	}
	file_k = open(to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
		exit(99);
	}
	n = read(file_n, buff, 1024);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
		exit(98);
	}
	while (n != 0)
	{
		k = write(file_k, buff, n);
		if (k == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s", to);
			exit(99);
		}
		n = read(file_n, buff, 1024);
		if (n == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
			exit(98);
		}
	}
	if (close(file_k) == -1)
	not_close(file_n);
	if (close(file_n) == -1)
	not_close(file_k);
}

/**
 * main - Copy a file into another file.
 * @argc: The size.
 * @argv: The character.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}
	if (argv[1] == NULL)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}
	cp(argv[1], argv[2]);
	return (0);
}
