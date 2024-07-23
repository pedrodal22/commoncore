/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:20:18 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/23 18:33:01 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_data *dados, char *map_name)
{
	char	*line;
	int		fd;
	int		a;
	int		i;

	fd = open(map_name, O_RDONLY);
	a = 0;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\n')
		{
			printf("%c", line[i]);
			if (line[i] == 'P')
			{
				dados->pos_inicial_y = a;
				dados->pos_inicial_x = i;
			}
			i++;
		}
		printf("\n");
		a++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void flood(t_data *dados, int y, int x)
{
    if (y < 0 || y >= dados->mapa_linhas || x < 0 || x >= dados->mapa_colunas)
		return ;
	if (dados->flood_mapa[y][x] == '1' || dados->flood_mapa[y][x] == 'A' || dados->flood_mapa[y][x] == 'X' || dados->flood_mapa[y][x] == 'T')
        return ;
    

    if (dados->flood_mapa[y][x] == 'P')
    {
        dados->flood_player_count++;
        printf("Found player at (%d, %d)\n", y, x);
    }
    if (dados->flood_mapa[y][x] == 'C')
    {
        dados->flood_colet_count++;
        printf("Found collectible at (%d, %d)\n", y, x);
    }
    if (dados->flood_mapa[y][x] == 'E')
        dados->flood_exit_count++;

    dados->flood_mapa[y][x] = 'A';

    flood(dados, y + 1, x);
    flood(dados, y - 1, x);
    flood(dados, y, x + 1);
    flood(dados, y, x - 1);
}


int	flood_fill(t_data *dados)
{
	dados->flood_player_count = 0;
	dados->flood_exit_count = 0;
	dados->flood_colet_count = 0;
	for (int y = 0; y < dados->mapa_linhas; y++) {
        for (int x = 0; x < dados->mapa_colunas; x++) {
            printf("%c", dados->flood_mapa[y][x]);
        }
		printf("\n");
	}
	printf("%i %i\n", dados->pos_atual_y, dados->pos_atual_x);
	flood(dados, dados->pos_atual_y, dados->pos_atual_x);
	for (int y = 0; y < dados->mapa_linhas; y++) {
        for (int x = 0; x < dados->mapa_colunas; x++) {
            printf("%c", dados->flood_mapa[y][x]);
        }
        printf("\n");
    }
	printf("player: %i\ncolet: %i\nexit: %i\n", dados->flood_player_count, dados->flood_colet_count, dados->flood_exit_count);
	if (dados->flood_player_count == 1 && dados->flood_colet_count
		== dados->colet_total && dados->flood_exit_count == 1)
			return (0);
	else
		return (1);
}
