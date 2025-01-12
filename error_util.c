/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:50:43 by meandrad          #+#    #+#             */
/*   Updated: 2025/01/12 13:21:58 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(int index)
{
	if (index == 1)
		perror("Falha ao criar o pipe");
	else if (index == 2)
		perror("Falha ao criar o processo");
	else if (index == 3)
	{
		perror("Quantidade de arumentos inválida");
		write(1, "\033[33mEx: ./pipex infile cmd1 cmd2 outfile", 37);
	}
	else if (index == 4)
		perror("Falha ao abrir o arquivo");
	else if (index == 5)
		perror("Caminho inválido");
	else if (index == 6)
		perror("Comando não encontrado");
	exit(EXIT_FAILURE);
}
