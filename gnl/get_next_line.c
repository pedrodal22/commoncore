/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:50:58 by pfranco-          #+#    #+#             */
/*   Updated: 2023/12/26 16:50:58 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i;
	char *linha;
	static char buffer[BUFFER_SIZE + 1];

	linha = NULL;
	if(BUFFER_SIZE <= 0 || read(fd, buffer, sizeof(buffer)) < 0)
		return(NULL);
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
	{
		linha = (char *)malloc(i + 1) * sizeof(char);
		if (linha == NULL)
			return (NULL);
		while (*buffer != NULL || read(fd, buffer, BUFFER_SIZE) > 0)
			linha = ft_strncpy(linha, buffer, i);
		linha[i] = '\0';
		return (linha);
	}
	return (NULL);
}
