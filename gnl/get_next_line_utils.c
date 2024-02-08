/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:38:25 by pfranco-          #+#    #+#             */
/*   Updated: 2024/02/06 12:32:12 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		i;
	int		h;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (str == NULL)
		return (line);
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	h = 0;
	while (buffer[h] != '\0')
	{
		str[i] = buffer[h];
		i++;
		if (buffer[h] == '\n')
			break ;
		h++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}