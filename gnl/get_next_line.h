#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*get_next_line(int fd);
#endif
