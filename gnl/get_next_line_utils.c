/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:37:29 by pedro             #+#    #+#             */
/*   Updated: 2024/01/20 18:37:29 by pedro            ###   ########.fr       */
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
		return (NULL);
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
