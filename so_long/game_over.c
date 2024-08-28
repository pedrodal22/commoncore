/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:23:25 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 13:38:50 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_data *dados, int type)
{
	if (type == 0)
		ft_printf("You've found the hiding spot!\nYou've won!\n");
	else if (type == 1)
		ft_printf("You found the Sheriff...\n");
	else if (type == 2)
		ft_printf("The Sheriff has found you...\n");
	else if (type == 3)
		ft_printf("You've stepped on a TNT...\n");
	destruir(dados, 0);
}

void	print_errors(int error)
{
	if (error == 0)
		ft_printf("Error\nThe map's wall are not written as expected.\n");
	if (error == 1)
		ft_printf("Error.\nThe map contains invalid characters.\n");
	if (error == 2)
		ft_printf("Error\nThere is no valid path to the exit/a collectible.\n");
}
