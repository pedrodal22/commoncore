/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:36:38 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 12:38:07 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapa_valido(char **argv, t_data *dados)
{
	int	player_count;
	int	exit_count;
	int	fd;

	player_count = 0;
	exit_count = 0;
	dados->colet_total = 0;
	dados->colet_count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	elementos_mapa(dados, &player_count, &exit_count, fd);
	close(fd);
	if (player_count == 1 && exit_count == 1 && dados->colet_total >= 1
		&& dados->num_enemies <= 1)
		return (0);
	ft_printf("Error\nThe map is invalid.\n");
	return (1);
}

int	check_invalid_char(int fd)
{
	char	*str;
	char	*string_original;
	int		check;

	check = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		string_original = str;
		while (*str != '\n' && *str != '\0')
		{
			if (*str != '0' && *str != '1' && *str != 'E' && *str != 'P'
				&& *str != 'T' && *str != 'C' && *str != 'X')
				check = 1;
			str++;
		}
		free(string_original);
		if (check == 1)
			return (print_errors(1), 1);
		str = get_next_line(fd);
	}
	return (0);
}
