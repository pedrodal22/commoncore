/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:46:04 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/31 14:12:55 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(int argc, char **argv, t_data *dados)
{
	int	a;

	a = check_nome_ficheiro(argc, argv);
	a += check_mapa_valido(argv, dados);
	if (a != 0)
		return (1);
	return (0);
}

int	check_nome_ficheiro(int argc, char **argv)
{
	int	a;

	a = 0;
	if (argc != 2)
		return (1);
	while (argv[1][a] != '.' && argv[1][a] != '\0')
		a++;
	if (a == 0)
		return (1);
	if (argv[1][a + 1] == 'b' && argv[1][a + 2] == 'e' && argv[1][a + 3] == 'r')
		return (0);
	return (1);
}

void	elementos_mapa(t_data *dados, int *player_count,
	int *exit_count, int fd)
{
	char	*str;
	char	*original_str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		original_str = str;
		while (*str != '\0')
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
		free(original_str);
		str = get_next_line(fd);
	}
	free(str);
}

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
	if (player_count != 1 || exit_count != 1 || dados->colet_total < 1 || dados->num_enemies > 1)
		return (1);
	return (0);
}
