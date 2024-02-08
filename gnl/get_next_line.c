/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:50:58 by pfranco-          #+#    #+#             */
/*   Updated: 2024/02/08 14:50:05 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

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
	printf("1(%s)\n", buffer);
}

int	checkline(char *buffer)
{
	int	i;
	// limpar buffer a zeros e mover informacao depois do newline
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
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

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0 || *buffer)
	{
		i = checkline(buffer);
		//printf("buffer antes de ser limpo: |%s|\n", buffer);
		line = ft_strjoin(line, buffer);
		clear(buffer, i);
		//printf("buffer depois de ser limpo: |%s|\n", buffer);
		if (i > 0)
			break;
	}
	i = 0;
	if (bytesRead < 0)
	{
		while (buffer[i])
			buffer[i] = 0;
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
        printf("%s", line);
        free(line);
    }

    // close(fd);
    return 0;
} */


int main(void)
{

	(clear(strdup("ab"), checkline("ab")));
	(clear(strdup("\nc"), checkline("\nc")));
	(clear(strdup("de"), checkline("de")));
}