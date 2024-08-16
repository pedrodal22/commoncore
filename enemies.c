/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:45 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/09 16:56:07 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inimigos_init(t_data *dados)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < dados->mapa_linhas)
	{
		while (x < dados->mapa_colunas)
		{
			if (dados->mapa[y][x] == 'X')
			{
				dados->enemy_y = y * 64;
				dados->enemy_x = x * 64;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	move_inimigos(t_data *dados)
{
	move_inimigos_ad(dados);
	return (1);
}

void	move_inimigos_ad(t_data *dados)
{
	static int	move;
	static int	count;
	int			x;

	if (!move)
		move = 1;
	if (!count)
		count = 0;
	count += 1;
	x = dados->enemy_x;
	if (count >= 25000)
	{
		count = 0;
		if (dados->mapa[dados->enemy_y / 64][(x / 64) + move] != '0'
			&& dados->mapa[dados->enemy_y / 64][(x / 64) + move] != 'X')
			move *= -1;
		if (((x / 64) + move == dados->pos_atual_x)
			&& ((dados->enemy_y / 64) == dados->pos_atual_y))
			{
				game_over(dados, 2);
				exit (1);
			}
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_sand, dados->enemy_x, dados->enemy_y);
		dados->enemy_x = (dados->enemy_x + (64 * move));
		mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr,
			dados->img_ptr_cop, dados->enemy_x, dados->enemy_y);
	}
}
