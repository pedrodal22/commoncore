#include <stdio.h>

void *ft_memmove(void *str1, const void *str2, size_t n)
{
    int i;
    unsigned char *cdest = (unsigned char *) str1;
    unsigned char *csrc =  (unsigned char *) str2;

    i = 0;
    while (csrc[i] != '\0' && i < n)
    {
        cdest[i] = csrc[i];
        i++;
    }
    return str1;
}

int main()
{
    char source[] = "Hello, world!";
    char dest[] = "Goodbye, world!";
    int size = 5;
    
    printf("Source: %s\n", source);
    printf("Destination: %s\n", dest);

    ft_memmove(dest, source, size);

    printf("\n\nSource: %s\n", source);
    printf("Destination: %s\n", dest);

    return 0;
}