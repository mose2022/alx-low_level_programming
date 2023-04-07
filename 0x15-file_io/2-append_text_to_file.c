#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of text file in the code.
 * @text_content: The conent of the file.
 * Return: On success, 1.
 * On failure, 0.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int name, n = 0;
	if (!filename)
		return (-1);

	name = open(filename, O_WRONLY | O_APPEND);
	if (name == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	while (text_content[n])
		n++;

	write(name, text_content,n);
	close(name);

	return (1);
}
