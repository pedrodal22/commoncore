/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:59:07 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/01 19:23:21 by pfranco-         ###   ########.fr       */
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

int	check_start(int argc, char **argv, t_data *dados)
{
	dados->mlx_ptr = mlx_init();
	if (dados->mlx_ptr == NULL || check_all(argc, argv, dados) == 1)
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

int	main(int argc, char *argv[])
{
	t_data	dados;

	if (check_start(argc, argv, &dados) != 0)
		return (free_all(&dados), 1);
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
