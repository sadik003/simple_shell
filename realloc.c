#include "shell.h"

/**
 **_memset - this fuunction fills memory with a constant byte
 *@s: pointer to the memory area
 *@b: byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	/* declaration */
	unsigned int k;

	for (k = 0; k < n; k++)
		s[k] = b;
	return (s);
}

/**
 * ffree - the function frees a string of strings
 * @pp: strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - this function reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/* declaration */
	char *k;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	k = malloc(new_size);
	if (!k)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		k[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (k);
}
