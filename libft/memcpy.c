#include <stdio.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    int i;
    unsigned char *cdest = (unsigned char *) dest;
    unsigned char *csrc =  (unsigned char *) src;

    i = 0;
    while (csrc[i] != '\0' && i < n)
    {
        cdest[i] = csrc[i];
        i++;
    }
    return dest;
}

int main()
{
    char source[] = "Hello, world!";
    int size = 5;
    char destination[size];

    memcpy(destination, source, size);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}