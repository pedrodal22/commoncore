#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
#endif
