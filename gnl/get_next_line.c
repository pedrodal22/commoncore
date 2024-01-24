/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:37:49 by pedro             #+#    #+#             */
/*   Updated: 2024/01/20 18:37:49 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear(char *c, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (c[i])
	{
		if (index != 0 && i >= index)
		{
			c[count++] = c[i];
		}
		c[i] = '\0';
		i++;
	}
}

int	checkline(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
    char	*line;
    static	char buffer[BUFFER_SIZE + 1];
    int		bytesRead;
	int		i;

	*line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0 || *buffer)
	{
		i = checkline(buffer);
		line = ft_strjoin(line, buffer);
		clear(buffer, i);
		if (i > 0)
			break;

	}
	if (bytesRead < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* int main(void)
{
    int fd = open("ola.txt", O_RDONLY);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line read:%s", line);
        free(line); // Free the line after processing
    }

    close(fd);
    return 0;
} */
