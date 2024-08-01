/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:59:07 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/01 12:38:37 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_data *dados)
{
	ft_printf("Game Over!");
	destruir(dados);
}

void	start_all(t_data *dados, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	mapa_linhas_colunas(dados, fd);
	allocate_struct_map(dados->mapa_linhas, dados->mapa_colunas, dados);
	fd = open(map, O_RDONLY);
	create_map(dados, fd);
	fd = open(map, O_RDONLY);
	find_player(dados, fd);
	dados->pos_atual_x = dados->pos_inicial_x;
	dados->pos_atual_y = dados->pos_inicial_y;
	inimigos_init(dados);
}

int	main(int argc, char *argv[])
{
	t_data	dados;

	dados.mlx_ptr = mlx_init();
	if (dados.mlx_ptr == NULL || check_all(argc, argv, &dados) == 1)
	{
		free_all(&dados);
		ft_printf("Error\n");
		return (1);
	}
	start_all(&dados, argv[1]);
	if (check_walls(&dados) == 0 && flood_fill(&dados) == 0)
	{
		dados.win_ptr = mlx_new_window(dados.mlx_ptr, (dados.mapa_colunas * 64),
				(dados.mapa_linhas * 64), "hi :)");
		if (dados.win_ptr == NULL)
			return (free_all(&dados), 1);
		create_images(&dados, 64, 64);
		map_images(&dados);
		mlx_hook(dados.win_ptr, KeyRelease, KeyReleaseMask, &tecla, &dados);
		if (dados.num_enemies == 1)
			mlx_loop_hook(dados.mlx_ptr, move_inimigos, &dados);
		mlx_hook(dados.win_ptr, DestroyNotify, StructureNotifyMask,
			&destruir, &dados);
		mlx_loop(dados.mlx_ptr);
	}
	free_all(&dados);
	return (0);
}
