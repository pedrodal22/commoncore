/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:59:07 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/31 16:34:23 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_over(t_data *dados)
{
	ft_printf("Game Over!");
	destruir(dados);
}

void initialize_data(t_data *dados)
{
    // Inicializa ponteiros
    dados->mapa = NULL;
    dados->flood_mapa = NULL;
    dados->mlx_ptr = NULL;
    dados->win_ptr = NULL;
    dados->img_ptr_sand = NULL;
    dados->img_ptr_cato = NULL;
    dados->img_ptr_cowboy = NULL;
    dados->img_ptr_colet = NULL;
    dados->img_ptr_exit = NULL;
    dados->img_ptr_din = NULL;
    dados->img_ptr_cop = NULL;

    // Inicializa valores inteiros
    dados->x_mapa = 0;
    dados->y_mapa = 0;
    dados->flood_mapa_x = 0;
    dados->flood_mapa_y = 0;
    dados->flood_player_count = 0;
    dados->flood_colet_count = 0;
    dados->flood_exit_count = 0;
    dados->mapa_colunas = 0;
    dados->mapa_linhas = 0;
    dados->pos_inicial_x = 0;
    dados->pos_inicial_y = 0;
    dados->pos_atual_x = 0;
    dados->pos_atual_y = 0;
    dados->exit_pos_x = 0;
    dados->exit_pos_y = 0;
    dados->colet_total = 0;
    dados->colet_count = 0;
    dados->num_enemies = 0;
    dados->enemy_x = 0;
    dados->enemy_y = 0;
    dados->enemy_direction = 0;
    dados->count_moves = 0;
}


int	main(int argc, char *argv[])
{
	t_data	dados;

	initialize_data(&dados);
	dados.mlx_ptr = mlx_init();
	dados.count_moves = 0;
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
		mlx_hook(dados.win_ptr, KeyRelease, KeyReleaseMask, &tecla, &dados);
		if (dados.num_enemies == 1)
			mlx_loop_hook(dados.mlx_ptr, move_inimigos, &dados);
		mlx_hook(dados.win_ptr, DestroyNotify, StructureNotifyMask, &destruir, &dados);
		mlx_loop(dados.mlx_ptr);
	}
	free_all(&dados);
	return (0);
}
