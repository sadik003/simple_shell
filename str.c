#include "shell.h"

/**
 * _strdup - a function to duplicates a string
 * @s: the string
 *
 * Return: pointer to the duplicate
 */
char *_strdup(char *s)
{
/* declation of variable */
	int size, i = 0;
	char *dest;

	if (!s)
		return (NULL);
	size = _strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (NULL);

	while (i < size)
	{
		*(dest + i) = *(s + i);
		i++;
	}
	*(dest + i) = '\0';

	return (dest);
}
/**
 * _strcat - this function concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: result of concatenation
 */
char *_strcat(char *dest, const char *src)
{
	/* declaration and initialization */
	int len_dest, i = 0;

	len_dest = _strlen(dest);

	while (src[i])
		dest[len_dest++] = src[i++];
	dest[len_dest] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if equal, -ve if @s1 < @s2, else +ve
 */
int _strcmp(char *s1, char *s2)
{
/* declaratio */
	int k;

	for (k = 0; s1[k]; k++)
		if (s1[k] != s2[k])
			return (s1[k] - s2[k]);

	return (0);
}
