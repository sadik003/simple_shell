#include "shell.h"

/**
 * rm_newline - This function Removes the new line from User's input
 * @line: the line inputted by user
 *
 * Return: input without newline
 */
char *rm_newline(char *line)
{
/* ........... initialization .................... */
	char *temp = line;

	temp = strtok(temp, "\n");
	return (temp);
}

/**
 * parse_input - this function parses the line entered by the user
 * @line: input
 *
 * Return: an array of tokens present in @line
 */
char **parse_input(char *line)
{
/* ....................initializing variables ...................... */
	char **tokens;
	char *tok, *temp;
	int j;

	if (!line)
		return (NULL);

	tokens = malloc(sizeof(char *) * _strlen(line));
	if (!tokens)
	{
		perror("Gsh");
		return (NULL);
	}

	line = rm_newline(line);

	temp = _strdup(line);
	tok = strtok(temp, " ");
	for (j = 0; tok; j++)
	{
		tokens[j] = _strdup(tok);
		tok = strtok(NULL, " ");
	}
	tokens[j] = NULL;

	free(temp);

	return (tokens);
}

/**
 * build_path - the funtion build the path to a command
 * @token: the given command
 * @value: the path to build for @token
 *
 * Return: @value/@token - the path of command
 */
char *build_path(char *token, char *value)
{
/* variable initialization */
	char *cm;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cm = malloc(sizeof(char) * len);
	if (!cm)
		return (NULL);
	memset(cm, 0, len);

	cm = _strcat(cm, value);
	cm = _strcat(cm, "/");
	cm = _strcat(cm, token);

	return (cm);
}

/**
 * check_cmd_path - to check if command is in path
 * @cmd: array of command strings
 *
 * Return: 0 if found, else 1
 */
int check_cmd_path(char **cmd)
{
/* initializing the variables */
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _environs("PATH");
	value = strtok(path, ":");
	while (value)
	{
		cmd_path = build_path(*cmd, value);

		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}

	return (1);
}
