/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:50:58 by pfranco-          #+#    #+#             */
/*   Updated: 2024/02/14 17:35:53 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			index;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		clear(buffer, 0);
		return (NULL);
	}
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		index = checkline(buffer);
		line = ft_strjoin(line, buffer);
		clear(buffer, index);
		if (index > 0)
			break ;
	}
	if (line == NULL)
	{
		while (buffer[0])
			buffer[0] = 0;
		return (NULL);
	}
	return (line);
}

/* int main(void)
{
    int fd = open("a.txt", O_RDONLY);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	close(fd);
    return 0;
} */