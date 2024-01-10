#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		i++;
	return(i);
}

char *ft_strjoin(char *line, char *buffer)
{
	char *str;
	int i;
	int h;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if(str == NULL)
		return (NULL);
	while(*line != '\0')
	{
		str[i] = *line;
		i++;
		*line++;
	}
	h = 0;
	while(*buffer != '\0')
	{
		str[i] = buffer[h];
		if(buffer[h] == '\n')
			break ;
		h++;
	}
	free(line);
	str[i] = '\0';
	return (str);
}
