#include "shell.h"

/**
 * executor - execute users input command
 * @cmd: command entered by user
 * @filename: file name of the file
 *
 * Return: void
 */
int executor(char **cmd, char *filename)
{
	int status;
	pid_t pid1;

	if (!*cmd)
		exit(-1);
/* ....................... CALLING THE FORK FUNCTION TO ........  */

	pid1 = fork();

	if (pid1 == -1)
	{
		perror("Error");
		exit(-1);
	}

	if (pid1 == 0)
	{
		if (strncmp(cmd[0], "./", 2) && strncmp(cmd[0], "/", 1))
			check_cmd_path(cmd);

		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(filename);
			free_memory_pp(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
