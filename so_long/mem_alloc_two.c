/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:02:32 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 13:03:23 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_lines_columns(t_data *dados, int fd)
{
	char	*line;
	int		linhas;
	int		colunas;
	int		i;

	linhas = 0;
	colunas = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (colunas == -1 && i > 0)
			colunas = i;
		if (i > 0)
			linhas++;
		free(line);
		line = get_next_line(fd);
	}
	dados->mapa_colunas = colunas;
	dados->mapa_linhas = linhas;
	free(line);
	close(fd);
	check_new_line(dados, fd);
}

void	check_new_line(t_data *dados, int fd)
{
	char	*line;
	int		tab_count;
	int		i;

	tab_count = 0;
	fd = open(dados->map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i++] == '\n')
			{
				tab_count++;
				break ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (tab_count >= dados->mapa_linhas)
		check_new_line_error(dados);
}

void	check_new_line_error(t_data *dados)
{
	print_errors(1);
	destruir(dados, 1);
}
