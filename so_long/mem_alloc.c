/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:44 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 13:03:08 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			return (free_check(dados, 0), 1);
		x++;
	}
	while (y < dados->mapa_linhas)
	{
		if (dados->mapa[y][0] != '1'
		|| dados->mapa[y][dados->mapa_colunas - 1] != '1')
			return (free_check(dados, 0), 1);
		y++;
	}
	return (0);
}
