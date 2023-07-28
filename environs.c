#include "shell.h"

/**
 * _environs - value of an environmental variable
 * @name: the variable name
 *
 * Return: the value of @name
 */
char *_environs(const char *name)
{
/* .................... INITIALIZATION ........................ */

	int i = 0, j = 0;

	while (environ[i])
	{
		while (environ[i][j] && *name)
		{
			if (environ[i][j] != *name || (environ[i][j] == '='))
				break;
			j++, name++;
		}

		if (environ[i][j] == '=' && !*name)
			return ((*(environ + i) + ++j));
		i++;
	}

	return (NULL);
}
