/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:54 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/31 16:22:15 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves_all(int keysym)
{
	int	px;

	px = 0;
	if (keysym == 'w' || keysym == 'a')
		px = -64;
	else if (keysym == 's' || keysym == 'd')
		px = 64;
	return (px);
}

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
		game_over(dados);
	if (dados->enemy_x == x && dados->enemy_y == y + i)
		game_over(dados);
	if (dados->mapa[((y + i) / 64)][(x / 64)] == 'E' &&
	dados->colet_count == dados->colet_total)
		destruir(dados);
	if (dados->mapa[((y + i) / 64)][(x / 64)] == 'C')
	{
		dados->colet_count++;
		dados->mapa[((y + i) / 64)][(x / 64)] = '0';
	}
	dados->pos_atual_y += i / 64;
	y += i;
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_sand, x, previous_y);
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_cowboy, x, y);
	dados->count_moves++;
	display_moves(dados);
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
		game_over(dados);
	if (dados->enemy_x == x + i && dados->enemy_y == y)
		game_over(dados);
	if (dados->mapa[((y) / 64)][((x + i) / 64)] == 'E' && dados->colet_count
		== dados->colet_total)
		destruir(dados);
	if (dados->mapa[((y) / 64)][((x + i) / 64)] == 'C')
	{
		dados->colet_count++;
		dados->mapa[((y) / 64)][((x + i) / 64)] = '0';
	}
	dados->pos_atual_x += i / 64;
	x += i;
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_sand, previous_x, y);
	mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
		dados->img_ptr_cowboy, x, y);
	dados->count_moves++;
	display_moves(dados);
}

void	display_moves(t_data *dados)
{
	int a;
	int b;
	char *moves;

	a = 0;
	b = 0;

	while(b < 20)
	{
		while(a < 80)
		{
			mlx_pixel_put(dados->mlx_ptr, dados->win_ptr, 5 + a, 10 + b, 0x000000);
			a++;
		}
		a = 0;
		b++;
	}
	moves = ft_itoa(dados->count_moves);
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 10, 24, 0xFFFFFF, "Moves: ");
    mlx_string_put(dados->mlx_ptr, dados->win_ptr, 55, 24, 0xFFFFFF, moves);
	free(moves);
}