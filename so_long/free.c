/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:24:17 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 12:42:56 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_check(t_data *dados, int flag)
{
	print_errors(flag);
	free_all(dados, 1);
	free_images(dados);
	free_map(dados);
	free_map_flood(dados);
	exit (1);
}

void	free_all(t_data *dados, int flag)
{
	if (flag == 1)
	{
		mlx_destroy_display(dados->mlx_ptr);
		free(dados->mlx_ptr);
	}
	if (flag == 0)
	{
		free_images(dados);
		free_map(dados);
		free_map_flood(dados);
	}
}

void	free_images(t_data *dados)
{
	if (dados->img_ptr_cato)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_cato);
	if (dados->img_ptr_colet)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_colet);
	if (dados->img_ptr_cowboy)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_cowboy);
	if (dados->img_ptr_exit)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_exit);
	if (dados->img_ptr_sand)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_sand);
	if (dados->img_ptr_cop)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_cop);
	if (dados->img_ptr_din)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr_din);
}

void	free_map(t_data *dados)
{
	int	i;

	i = 0;
	if (dados->mapa)
	{
		while (i < dados->mapa_linhas)
		{
			free(dados->mapa[i]);
			i++;
		}
		free(dados->mapa);
		dados->mapa = NULL;
	}
}

void	free_map_flood(t_data *dados)
{
	int	i;

	i = 0;
	if (dados->flood_mapa)
	{
		while (i < dados->mapa_linhas)
		{
			free(dados->flood_mapa[i]);
			i++;
		}
		free(dados->flood_mapa);
		dados->flood_mapa = NULL;
	}
}
