/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:36:41 by meandrad          #+#    #+#             */
/*   Updated: 2025/01/12 12:02:05 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(int *fd, char *argv[], char *envp[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		handle_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	cmd_execute(argv[2], envp);
}
void	child2_process(int *fd, char *argv[], char *envp[])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		handle_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	cmd_execute(argv[3], envp);
}
int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid[2];
	int		fd[2];
	
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			handle_error();
		pid[0] = fork();
		if (pid[0] == -1)
			handle_error();
		else if (pid[0] == 0)
			child1_process(fd, argv, envp);
		pid[1] = fork();
		if (pid[1] == - 1)
			handle_error();
		else if (pid[1] == 0)
			child2_process(fd, argv, envp);
		waitpid(pid[0], NULL, 0);
		waitpid(pid[1], NULL, 0);
	} 
	else
		handle_error();
	return (0);
}
