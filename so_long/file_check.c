/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:46:04 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/28 13:37:09 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(int argc, char **argv, t_data *dados)
{
	int	a;
	int	fd;

	a = check_nome_ficheiro(argc, argv);
	a += check_mapa_valido(argv, dados);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	a += check_invalid_char(fd);
	close(fd);
	dados->count_moves = 0;
	if (a != 0)
		return (1);
	return (0);
}

int	check_nome_ficheiro(int argc, char **argv)
{
	int	a;

	a = 0;
	(void) argc;
	while (argv[1][a] != '.' && argv[1][a] != '\0')
		a++;
	if (a == 0)
		return (1);
	if (argv[1][a] == '.' && argv[1][a + 1] == 'b' && argv[1][a + 2] == 'e'
		&& argv[1][a + 3] == 'r')
		return (0);
	ft_printf("Error\nThe map, as an argument, is invalid.\n");
	return (1);
}

void	contar_elementos_linha(char *str, t_data *dados,
	int *player_count, int *exit_count)
{
	while (*str)
	{
		if (*str == 'P')
			(*player_count)++;
		else if (*str == 'C')
			dados->colet_total++;
		else if (*str == 'E')
			(*exit_count)++;
		else if (*str == 'X')
			dados->num_enemies++;
		str++;
	}
}

void	elementos_mapa(t_data *dados, int *player_count,
	int *exit_count, int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str && *str != '\n')
	{
		if (*str == '\n')
		{
			free(str);
			free_check(dados, 3);
			return ;
		}
		contar_elementos_linha(str, dados, player_count, exit_count);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}
