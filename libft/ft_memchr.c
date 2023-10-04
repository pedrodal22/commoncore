#include <stdio.h>

void *my_memchr(const void *s, int c, size_t n)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return((char*)&str[i]);
        }
        i++;
    }
    return (NULL);
}