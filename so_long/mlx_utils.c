/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:15:51 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/08 16:13:00 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tecla(int keysym, t_data *dados)
{
	int	px;

	if (keysym == 65307)
		destruir(dados);
	if (keysym == 'w' || keysym == 'd' || keysym == 'a' || keysym == 's')
	{
		px = moves_all(keysym);
		moves(dados, keysym, px);
	}
	return (0);
}

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

int	destruir(t_data *dados)
{
	free_all(dados, 0);
	mlx_destroy_display(dados->mlx_ptr);
	mlx_destroy_window(dados->mlx_ptr, dados->win_ptr);
	free(dados->mlx_ptr);
	free(dados->win_ptr);
	return (0);
}

void	display_moves(t_data *dados)
{
	int		a;
	int		b;
	char	*moves;

	a = 0;
	b = 0;
	while (b < 40)
	{
		while (a < 80)
		{
			mlx_pixel_put(dados->mlx_ptr, dados->win_ptr,
				5 + a, 10 + b, 0x000000);
			a++;
		}
		a = 0;
		b++;
	}
	moves = ft_itoa(dados->count_moves);
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 10, 24, 0xFFFFFF, "Moves: ");
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 55, 24, 0xFFFFFF, moves);
	display_colet(dados);
	free(moves);
}

void	display_colet(t_data *dados)
{
	char	*colet_count;
	char	*colet_total;

	colet_count = ft_itoa(dados->colet_count);
	colet_total = ft_itoa(dados->colet_total);
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 10, 40, 0xFFFFFF, "Itens: ");
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 55, 40,
		0xFFFFFF, colet_count);
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 60, 40,
		0xFFFFFF, " / ");
	mlx_string_put(dados->mlx_ptr, dados->win_ptr, 75, 40,
		0xFFFFFF, colet_total);
	free(colet_count);
	free(colet_total);
}
