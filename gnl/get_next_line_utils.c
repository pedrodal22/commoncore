/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:38:25 by pfranco-          #+#    #+#             */
/*   Updated: 2024/02/14 16:07:52 by pfranco-         ###   ########.fr       */
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

int	checkline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		i;
	int		h;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(line) + ft_strlen(buffer) + 1);
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

void	clear(char *buffer, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (index != 0 && i >= index)
			buffer[count++] = buffer[i];
		buffer[i++] = '\0';
	}
}
