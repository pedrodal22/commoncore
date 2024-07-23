/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:15:51 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/20 00:47:14 by pfranco-         ###   ########.fr       */
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

int	destruir(t_data *dados)
{
	mlx_destroy_window(dados->mlx_ptr, dados->win_ptr);
	mlx_destroy_display(dados->mlx_ptr);
	free(dados->mlx_ptr);
	exit (0);
	return (0);
}
