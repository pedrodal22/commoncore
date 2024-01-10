/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:50:58 by pfranco-          #+#    #+#             */
/*   Updated: 2023/12/27 15:55:14 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clear(char *c, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(c[i])
	{	
		if (index != 0 && i >= index)
		{
			c[count++] = c[i];
		}
		c[i] = '\0';
		i++;
	}
}

int checkline(char *c)
{
	int i;

	i = 0;
	while(c[i])
	{	
		if (c[i] == '\n')
			return(i + 1);
		i++;
	}
	return(0);
}

char *get_next_line(int fd)
{
	int i;
	char *line;
	static char buffer[BUFFER_SIZE + 1];

	line = NULL;
	if(BUFFER_SIZE <= 0)
		return(NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{	
		i = checkline(buffer);
		line = ft_strjoin(line, buffer);
		printf("%s", line);
		clear(buffer, i);
		if(i > 0)
			break;
		//TO DO - stop printing after reaching /n
		
	}
	return (line);
}

int main()
{
	int fd = open("j.txt", O_RDONLY);
	printf("FD: %i\n", (fd));

	printf(" _T1: %s\n", get_next_line(fd));
	printf(" _T2: %s\n", get_next_line(fd));
}