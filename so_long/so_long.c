/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:59:07 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/23 18:41:47 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_over(t_data *dados)
{
	printf("Game Over!");
	destruir(dados);
}

int	main(int argc, char *argv[])
{
	t_data	dados;
	// int a;

	// a = 0;
	dados.mlx_ptr = mlx_init();
	if (dados.mlx_ptr == NULL || check_all(argc, argv, &dados) == 1)
		return (free(dados.mlx_ptr), 1);
	mapa_linhas_colunas(&dados, argv[1]);
	allocate_struct_map(dados.mapa_linhas, dados.mapa_colunas, &dados);
	create_map(&dados, argv[1]);
	find_player(&dados, argv[1]);
	inimigos_init(&dados);
	dados.pos_atual_x = dados.pos_inicial_x;
	dados.pos_atual_y = dados.pos_inicial_y;
	if (check_walls(&dados) == 0 && flood_fill(&dados) == 0)
	{
		dados.win_ptr = mlx_new_window(dados.mlx_ptr, (dados.mapa_colunas * 64),
				(dados.mapa_linhas * 64), "hi :)");
		if (dados.win_ptr == NULL)
			return (free_all(&dados),1);
		create_images(&dados, 64, 64);
		map_images(&dados);
		mlx_loop_hook(dados.mlx_ptr, move_inimigos, &dados);
		mlx_hook(dados.win_ptr, KeyRelease, KeyReleaseMask, &tecla, &dados);
		mlx_hook(dados.win_ptr, DestroyNotify, StructureNotifyMask, &destruir, &dados);
		mlx_loop(dados.mlx_ptr);
	}
	free_all(&dados);
	return (0);
}
