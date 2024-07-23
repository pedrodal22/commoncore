/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:45 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/23 18:42:43 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_inimigos(t_data *dados)
{
    int index;

    index = 0;
	printf("nº de inimigos: %i\n", dados->num_enemies);
	dados->enemies[index].x = 0;
	dados->enemies[index].y = 0;
	while (index < dados->num_enemies)
	{
		printf("index: %i\n", index);
		if (dados->enemies[index].direction == 100)
			move_inimigos_ws(dados, index);
		else if (dados->enemies[index].direction == 200)
			move_inimigos_ad(dados, index);
		index++;
	}
	printf("\n");
	index = 0;
	return (1);
}

void inimigos_init(t_data *dados)
{
	int index;
	int y;
	int x;

	index = 0;
	y = 0;
	x = 0;
	dados->enemies = malloc(dados->num_enemies * sizeof(t_enemy));
	while (y < dados->mapa_linhas)
	{
		printf("ola\n");
		while (x < dados->mapa_colunas)
		{
			printf("adeus\n");
			if(dados->mapa[y][x] == 'X')
			{
				printf("\nindex: %i\n\n", index);
				dados->enemies[index].y = y;
				dados->enemies[index].x = x;
				if(((index + 1)/2) == 0)
				{
					printf("%i\n", dados->enemies[index].direction);
					dados->enemies[index].direction = 200;

				}
				else
				{
					printf("%i\n", dados->enemies[index].direction);
					dados->enemies[index].direction = 100;
				}
				index++;
			}	
			x++;
		}
		x = 0;
		y++;
	}
}

void move_inimigos_ws(t_data *dados, int index)
{
	int novo_y;
	int move;

	move = 1;
	novo_y = 0;
	printf("Entrei ws\n");
	if (index < dados->num_enemies)
    {
        novo_y = dados->enemies[index].y + dados->enemies[index].direction;
		printf("direção: %i\ni:%i\n", dados->enemies[index].direction, index);
        if (novo_y < 0 || novo_y >= dados->mapa_colunas || dados->mapa[novo_y][dados->enemies[index].x] == '1')
            move *= -1;
        else
        {
            mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr, dados->img_ptr_sand, dados->enemies[index].x, dados->enemies[index].y);
            dados->enemies[index].y = novo_y;
            mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr, dados->img_ptr_cop, dados->enemies[index].x, dados->enemies[index].y);
        }
        index++;
    }
}

void move_inimigos_ad(t_data *dados, int index)
{
	int novo_x;
	int move;

	move = 1;
	novo_x = 0;
	printf("Entrei ad\n");
	if (index < dados->num_enemies)
    {
		dados->enemies[index].x = 0;
		dados->enemies[index].y = 0;
        novo_x = dados->enemies[index].y + dados->enemies[index].direction;
		printf("direção: %i\ni:%i\n", dados->enemies[index].direction, index);
        if (novo_x < 0 || novo_x >= dados->mapa_colunas || dados->mapa[novo_x][dados->enemies[index].x] == '1')
            move *= -1;
        else
        {
            mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr, dados->img_ptr_sand, dados->enemies[index].x, dados->enemies[index].y);
            dados->enemies[index].y = novo_x;
            mlx_put_image_to_window(dados->mlx_ptr, dados->win_ptr, dados->img_ptr_cop, dados->enemies[index].x, dados->enemies[index].y);
        }
        index++;
    }
}
