#include "main.h"
/**
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *full_path, char *path)
{
	unsigned int command_length, path_length, original_path_length;
	char *path_copy, *token;

	command_length = _strlen(command);
	original_path_length = _strlen(path);
	path_copy = malloc(sizeof(char) * original_path_length + 1);
	if (path_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(path_copy, path);
	/* copy PATH directory + command name and check if it exists */
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_length = _strlen(token);
		fullpath = malloc(sizeof(char) * (path_length + command_length) + 2);
		if (fullpath == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(full_path, token);
		fullpath[path_length] = '/';
		_strcpy(full_path + path_length + 1, command);
		fullpath[path_length + command_length + 1] = '\0';
		if (access(full_path, X_OK) != 0)
		{
			free(full_path);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (full_path);
}
