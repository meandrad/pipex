/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:35:01 by meandrad          #+#    #+#             */
/*   Updated: 2025/01/18 16:59:36 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

void	child1_process(int *fd, char *argv[], char *envp[]);
void	child2_process(int *fd, char *argv[], char *envp[]);
void	cmd_execute(char *argv, char *envp[]);
char	*find_path(char *cmd, char *envp[]);
void	handle_error(int error_code);
void	free_path(char **path);

#endif
