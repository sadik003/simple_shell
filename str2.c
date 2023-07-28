#include "shell.h"

/**
 * _strlen - function to finds the length of a string
 * @s: the given string
 *
 * Return: returns the length of the string
 */
int _strlen(const char *s)
{
/* declaration and initialization */
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;

	return (k);
}

/**
 * _strstr - this function is the Implementation of the strstr function
 * @haystack: Just as the name suggests
 * @needle: the string to be searched for
 *
 * Return: a pointer to the first character of @needle
 * in @haystack if found, else NULL
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if ((*haystack == *needle) && cmp(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (NULL);
}

/**
 * _strcpy - this function copies the content of a string to another
 * @dest: the destination string
 * @src: the source of the contents to be copied
 *
 * Return: @dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;

	while (*src)
		*temp++ = *src++;

	*temp = '\0';

	return (dest);
}
