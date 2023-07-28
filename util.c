#include "shell.h"

/**
 * free_memory_p - this function Frees a pointer
 *
 * @ptr: Pointer to free
 **/
void free_memory_p(char *ptr)
{
/* in case ptr points to no specific address */
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp - the function frees a double pointer
 *
 * @ptr: The double pointer to be freed
 **/
void free_memory_pp(char **ptr)
{
/* declaration of the double pointer */
	char **tmp;

	for (tmp = ptr; *tmp != NULL; tmp++)
		free_memory_p(*tmp);

	free(ptr);
}

/**
 * cmp - the function checks if a string in another
 * @s1: the string to be searched
 * @s2: the string being searched for
 *
 * Description: different from the _strcmp function
 * Return: 1 if found, else 0
 */
int cmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);

	return (*s2 == '\0');
}

/**
 * _isalpha -  this function checks if a character is a letter
 * @c: the given character
 *
 * Return: TRUE if true, else FALSE
 */
int _isalpha(char c)
{
	if ((c >= 48) && (c <= 57))
		return (FALSE);

	return (TRUE);
}

/**
 * _atoi - convert a string to an integer.
 * @s: the string to be converted.
 *
 * Return: int.
 */
int _atoi(char *s)
{
	int len, i = 0, FLAG = 0, d = 0, n = 0, digit;

	for (len = 0; s[len] != '\0'; len++)
		;

	while (i < len && FLAG == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= 48 && s[i] <= 57)
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			FLAG = 1;
			if (s[i + 1] < 48 || s[i + 1] > 57)
				break;
			FLAG = 0;
		}
		i++;
	}
	if (FLAG == 0)
		return (0);

	return (n);
}
