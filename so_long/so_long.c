/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:59:07 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/09 19:06:43 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_data *dados, int type)
{
	if (type == 0)
		printf("Encontras-te o esconderijo!\nGanhaste!\n");
	else if (type == 1)
		ft_printf("Encontraste-te o Xerife!\n");
	else if (type == 2)
		ft_printf("O Xerife encontrou-te!\n");
	else if (type == 3)
		ft_printf("Pisaste numa dinamite!\n");
	destruir(dados, 0);
}

void	start_all(t_data *dados, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	mapa_linhas_colunas(dados, fd);
	close(fd);
	allocate_struct_map(dados->mapa_linhas, dados->mapa_colunas, dados);
	fd = open(map, O_RDONLY);
	create_map(dados, fd);
	close(fd);
	fd = open(map, O_RDONLY);
	find_player(dados, fd);
	close(fd);
	dados->pos_atual_x = dados->pos_inicial_x;
	dados->pos_atual_y = dados->pos_inicial_y;
	inimigos_init(dados);
}

int	check_start(int argc, char **argv, t_data *dados)
{
	dados->mlx_ptr = mlx_init();
	if (check_all(argc, argv, dados) == 1 || dados->mlx_ptr == NULL)
		return (1);
	return (0);
}

void	print_errors(int error)
{
	if (error == 0)
		ft_printf("Error\nAs paredes do mapa são inválidas\n");
	if (error == 1)
		ft_printf("Error\nO mapa contém caractéres inválidos\n");
	if (error == 2)
		ft_printf("Error\nNão há um caminho válido até à saída/aos itens");
}

void innit(t_data *dados)
{
	dados->mapa = NULL;
	dados->x_mapa = 0;
	dados->y_mapa = 0;
	dados->flood_mapa = NULL;
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
	dados->mlx_ptr = NULL;
	dados->win_ptr = NULL;
	dados->img_ptr_sand = NULL;
	dados->img_ptr_cato = NULL;
	dados->img_ptr_cowboy = NULL;
	dados->img_ptr_colet = NULL;
	dados->img_ptr_exit = NULL;
	dados->img_ptr_din = NULL;
	dados->img_ptr_cop = NULL;
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

	if (argc != 2)
		exit (1);
	innit(&dados);
	if (check_start(argc, argv, &dados) != 0)
		return (destruir(&dados, 1), 1);
	start_all(&dados, argv[1]);
	if (check_walls(&dados) == 0 && flood_fill(&dados) == 0)
	{
		dados.win_ptr = mlx_new_window(dados.mlx_ptr, (dados.mapa_colunas * 64),
				(dados.mapa_linhas * 64), "so_long");
		if (dados.win_ptr == NULL)
			return (destruir(&dados, 0), 1);
		create_images(&dados, 64, 64);
		map_images(&dados);
		mlx_hook(dados.win_ptr, KeyRelease, KeyReleaseMask, &tecla, &dados);
		if (dados.num_enemies == 1)
			mlx_loop_hook(dados.mlx_ptr, move_inimigos, &dados);
		mlx_hook(dados.win_ptr, DestroyNotify, StructureNotifyMask, destruir, &dados);
		mlx_loop(dados.mlx_ptr);
	}
	return (0);
}
