/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:11:24 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/20 13:39:34 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_data *dados, int largura, int altura)
{
	dados->img_ptr_sand = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/areia64.xpm", &largura, &altura);
	dados->img_ptr_cowboy = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/cowboy64.xpm", &largura, &altura);
	dados->img_ptr_cato = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/cato64.xpm", &largura, &altura);
	dados->img_ptr_colet = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/coletavel64.xpm", &largura, &altura);
	dados->img_ptr_exit = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/exit_one64.xpm", &largura, &altura);
	dados->img_ptr_din = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/tnt64.xpm", &largura, &altura);
	dados->img_ptr_cop = mlx_xpm_file_to_image(dados->mlx_ptr,
			"assets/xerife64.xpm", &largura, &altura);
}

void	put_image(t_data *dados, int x, int y, char caracter)
{
	if (caracter == '0')
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_sand, x * 64, y * 64);
	else if (caracter == 'P')
	{
		dados->pos_inicial_x = x * 64;
		dados->pos_inicial_y = y * 64;
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_cowboy, x * 64, y * 64);
	}
	else if (caracter == '1')
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_cato, x * 64, y * 64);
	else if (caracter == 'E')
	{
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_exit, x * 64, y * 64);
		dados->exit_pos_x = x * 64;
		dados->exit_pos_y = y * 64;
	}
	else if (caracter == 'C')
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_colet, x * 64, y * 64);
	else if (caracter == 'T')
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_din, x * 64, y * 64);
	else if (caracter == 'X')
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_cop, x * 64, y * 64);
}

void	map_images(t_data *dados)
{
	int	x;
	int	y;

	y = 0;
	while (y < dados->mapa_linhas)
	{
		x = 0;
		while (x < dados->mapa_colunas)
		{
			put_image(dados, x, y, dados->mapa[y][x]);
			x++;
		}
		y++;
	}
}

// void initialize_data(t_data *dados)
// {
//     dados->mapa = NULL;
//     dados->flood_mapa = NULL;
//     dados->mlx_ptr = NULL;
//     dados->win_ptr = NULL;
//     dados->img_ptr_sand = NULL;
//     dados->img_ptr_cato = NULL;
//     dados->img_ptr_cowboy = NULL;
//     dados->img_ptr_colet = NULL;
//     dados->img_ptr_exit = NULL;
//     dados->x_mapa = 0;
//     dados->y_mapa = 0;
//     dados->flood_mapa_x = 0;
//     dados->flood_mapa_y = 0;
//     dados->flood_player_count = 0;
//     dados->flood_colet_count = 0;
//     dados->flood_exit_count = 0;
//     dados->mapa_colunas = 0;
//     dados->mapa_linhas = 0;
//     dados->pos_inicial_x = 0;
//     dados->pos_inicial_y = 0;
//     dados->pos_atual_x = 0;
//     dados->pos_atual_y = 0;
//     dados->exit_pos_x = 0;
//     dados->exit_pos_y = 0;
//     dados->colet_total = 0;
//     dados->colet_count = 0;
// }
