/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:54 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 13:21:18 by pfranco-         ###   ########.fr       */
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

void	moves_game_over(t_data *dados, int flag)
{
	game_over(dados, flag);
	exit(1);
}
