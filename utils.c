/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:04:15 by meandrad          #+#    #+#             */
/*   Updated: 2025/01/12 16:10:06 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

static char	*check_in_path(char *cmd, char **path)
{
	char	*part_path;
	char	*check_path;
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		part_path = ft_strjoin(path[i], "/");
		check_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(check_path, F_OK) == 0)
		{
			free_path(path);
			return (check_path);
		}
		free(check_path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char *envp[])
{
	char	**path;
	char	*result;
	int		i;

	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	result = check_in_path(cmd, path);
	free_path(path);
	return (result);
}

void	cmd_execute(char *argv, char *envp[])
{
	char	**cmd_args;
	char	*path;
	int		i;

	i = 0;
	cmd_args = ft_split(argv, ' ');
	path = find_path(cmd_args[0], envp);
	if (!path)
	{
		while (cmd_args[i])
			free(cmd_args[i++]);
		free(cmd_args);
		handle_error(5);
	}
	if (execve(path, cmd_args, envp) == -1)
	{
		while (cmd_args[i])
			free(cmd_args[i++]);
		free(cmd_args);
		free(path);
		handle_error(6);
	}
}
