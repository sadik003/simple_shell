#include "shell.h"

/**
 * _myunsetenv - This function Removes an environment variable
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i = 1; /* ......... variable declaration ........ */

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	while (i <= info->argc)
	{
		_unsetenv(info, info->argv[i]);
		i++;
	}
	return (0);
}

/**
 * populate_env_list -this function populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i = 0;

	while (environ[i])
	{
		add_node_end(&node, environ[i], 0);
		i++;
	}
	info->env = node;
	return (0);
}
/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i;

	if (!str)
		return;
	for (i = 0; str[i] != '\0'; i++)
	{
		_eputchar(str[i]);
	}
}

/**
 * _eputchar - the function writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd -this function  writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	/* ................... initialization ............ */
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
