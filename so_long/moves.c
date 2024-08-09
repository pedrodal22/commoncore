/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:54 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:07 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_data *dados, int keysym, int px)
{
	if (keysym == 'w' || keysym == 's')
		moves_ws(dados, px);
	else if (keysym == 'd' || keysym == 'a')
		moves_ad(dados, px);
}

void	moves_ws(t_data *dados, int i)
{
	int	previous_y;
	int	x;
	int	y;

	x = dados->pos_atual_x * 64;
	y = dados->pos_atual_y * 64;
	previous_y = y;
	if (dados->mapa[((y + i) / 64)][(x / 64)] == '1' ||
		(dados->mapa[((y + i) / 64)][(x / 64)] == 'E' && dados->colet_count !=
		dados->colet_total))
		return ;
	if (dados->mapa[((y + i) / 64)][(x / 64)] == 'T')
	{
		game_over(dados, 3);
		exit(1);
	}
	if (dados->enemy_x == x && dados->enemy_y == y + i)
	{
		game_over(dados, 3);
		exit(1);
	}
	else
		moves_ws2(dados, x, y, i);
	dados->pos_atual_y += i / 64;
	y += i;
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_sand, x, previous_y);
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_cowboy, x, y);
	dados->count_moves++;
	display_moves(dados);
}

void	moves_ws2(t_data *dados, int x, int y, int i)
{
	if (dados->mapa[((y + i) / 64)][(x / 64)] == 'E' &&
	dados->colet_count == dados->colet_total)
	{
		game_over(dados, 0);
		exit (1);
	}
	if (dados->mapa[((y + i) / 64)][(x / 64)] == 'C')
	{
		dados->colet_count++;
		dados->mapa[((y + i) / 64)][(x / 64)] = '0';
	}
}

void	moves_ad(t_data *dados, int i)
{
	int	previous_x;
	int	x;
	int	y;

	x = dados->pos_atual_x * 64;
	y = dados->pos_atual_y * 64;
	previous_x = x;
	if (dados->mapa[((y) / 64)][((x + i) / 64)] == '1' ||
		(dados->mapa[((y) / 64)][((x + i) / 64)] == 'E'
		&& dados->colet_count != dados->colet_total))
		return ;
	if (dados->mapa[((y) / 64)][((x + i) / 64)] == 'T')
	{
		game_over(dados, 3);
		exit(1);
	}
	if (dados->enemy_x == x + i && dados->enemy_y == y)
	{
		game_over(dados, 1);
		exit(1);
	}
	else
		moves_ad2(dados, x, y, i);
	dados->pos_atual_x += i / 64;
	x += i;
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_sand, previous_x, y);
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_cowboy, x, y);
	dados->count_moves++;
	display_moves(dados);
}

void	moves_ad2(t_data *dados, int x, int y, int i)
{
	if (dados->mapa[((y) / 64)][((x + i) / 64)] == 'E' && dados->colet_count
		== dados->colet_total)
		{
			game_over(dados, 0);
			exit(1);
		}
	if (dados->mapa[((y) / 64)][((x + i) / 64)] == 'C')
	{
		dados->colet_count++;
		dados->mapa[((y) / 64)][((x + i) / 64)] = '0';
	}
}
