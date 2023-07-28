#include "shell.h"

/**
 * is_builtin - this function check if a command is built in
 * @cmd: the given command
 *
 * Return: position of @cmd in the builtins array, else -1
 */
builtin_t is_builtin(char *cmd)
{
	builtin_t builtins[] = {
		{"exit", exit_cmd},
		{"env", env_cmd},
		{NULL, NULL}
	};

	int k;

	for (k = 0; builtins[k].cmd; k++)
		if (_strcmp(builtins[k].cmd, cmd) == 0)
			return (builtins[k]);

	return (builtins[k]);
}

/**
 * check_builtins - builtin command
 * @cmd: an array of command and its arguments
 *
 * Return: the appropriate function to be executed, else NULL
 */
int (*check_builtins(char **cmd))(char **, int, char *)
{
	builtin_t b = is_builtin(cmd[0]);

	if (b.cmd)
		return (b.f);

	return (NULL);
}

/**
 * env_cmd - builtin implementation of env command
 * @cmd: Unused
 * @filename: pointer to the filename
 * @status: the status code
 *
 * Return: Always 0
 */

int env_cmd(char **cmd, int status, char *filename)
{
	int k = 0;

	(void) cmd;
	(void) status;
	(void) filename;

	while (environ[k])
	{
		print(environ[k]);
		_putchar('\n');
		k = k + 1;
	}
	return (0);
}

/**
 * exit_cmd - The function for exit
 * @cmd: an array of given command and its arguments
 * @filename: the file
 * @status: the status code
 *
 * Return: exit with the status code given by user, or
 * previous execution status code
 */

int exit_cmd(char **cmd, int status, char *filename)
{
	int i = 0;

	if (!cmd[1])
	{
		free_memory_pp(cmd);
		exit(status);
	}

	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i]) && cmd[1][i] != '-')
		{
			print(filename);
			print(": ");
			print(cmd[0]);
			print(": ");
			print("Illegal number: ");
			print(cmd[1]);
			_putchar('\n');
			return (1);
		}

		i++;
	}

	status = _atoi(cmd[1]);
	free(cmd);

	exit(status);
}
