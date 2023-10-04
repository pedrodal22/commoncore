#include <stdio.h>

char *strrchr(const char *str, int c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    while (str[i] != str[0])
    {
        if (str[i] == c)
        {
            return((char*)&str[i]);
        }
        i--;
    }
    return (NULL);
}

/*
int main() {
    const char str[] = "Hello, World!";
    const char ch = 'o';

    char *result = strrchr(str, ch);

    if (result != NULL) {
        printf("O caractere '%c' foi encontrado na posição: %ld\n", ch, result - str);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", ch);
    }

    return 0;
}
*/
