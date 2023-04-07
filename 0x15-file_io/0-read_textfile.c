#include "main.h"

/**
 * read_textfile - eads a text file and prints it to the POSIX std output.
 * @filename: Textfile name.
 * @letters: Size.
 * Return: Actual number of letters it could read and print.
 * if the file can not be opened or read, return 0.
 */
 
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_desc, letters_read = 0;
    char *buffer;

    if (!filename)
        return (0);

    buffer = malloc((letters + 1) * sizeof(char));
    if (buffer == NULL)
        return (0);

    buffer[letters] = '\0';
    file_desc = open(filename, O_RDONLY);
    if (file_desc == -1)
        return (0);

    letters_read = read(file_desc, buffer, letters);
    write(STDOUT_FILENO, buffer, letters_read);
    close(file_desc);
    free(buffer);

    return letters_read;
}
