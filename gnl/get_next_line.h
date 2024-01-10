#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*get_next_line(int fd);
char *ft_strjoin(char *line, char *buffer);
int ft_strlen(char *str);
#endif