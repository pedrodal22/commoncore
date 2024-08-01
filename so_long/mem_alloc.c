/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:44 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/01 18:38:26 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapa_linhas_colunas(t_data *dados, int fd)
{
	char	*line;
	int		i;
	int		linhas;
	int		colunas;

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
	free(line);
	dados->mapa_colunas = colunas;
	dados->mapa_linhas = linhas;
	close(fd);
}

void	allocate_struct_map(int rows, int columns, t_data *dados)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	dados->mapa = (char **)malloc(rows * sizeof(char *));
	if (dados->mapa == NULL)
		return ;
	while (i < rows)
	{
		dados->mapa[i] = (char *)malloc((columns + 1) * sizeof(char));
		if (dados->mapa[i] == NULL)
		{
			while (j < i)
			{
				free(dados->mapa[j]);
				j++;
			}
			free(dados->mapa);
			return ;
		}
		i++;
	}
	allocate_flood_map(rows, columns, dados);
}

void	allocate_flood_map(int rows, int columns, t_data *dados)
{
	int		i;
	int		j;

	i = 0;
	dados->flood_mapa = (char **)malloc(rows * sizeof(char *));
	if (dados->flood_mapa == NULL)
		return ;
	while (i < rows)
	{
		dados->flood_mapa[i] = (char *)malloc((columns + 1) * sizeof(char));
		if (dados->flood_mapa[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(dados->flood_mapa[j]);
				j++;
			}
			free(dados->flood_mapa);
			exit(1);
		}
		i++;
	}
}

void	create_map(t_data *dados, int fd)
{
	char	*line;
	int		y;
	int		x;

	line = get_next_line(fd);
	y = 0;
	while (line != NULL && y < dados->mapa_linhas)
	{
		x = 0;
		while (x < dados->mapa_colunas && line[x] != '\0' && line[x] != '\n')
		{
			dados->mapa[y][x] = line[x];
			dados->flood_mapa[y][x] = line[x];
			x++;
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
}

int	check_walls(t_data *dados)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (x < dados->mapa_colunas)
	{
		if (dados->mapa[0][x] != '1'
			|| dados->mapa[dados->mapa_linhas - 1][x] != '1')
			return (print_errors(0), 1);
		x++;
	}
	while (y < dados->mapa_linhas)
	{
		if (dados->mapa[y][0] != '1'
		|| dados->mapa[y][dados->mapa_colunas - 1] != '1')
			return (print_errors(0), 1);
		y++;
	}
	return (0);
}
