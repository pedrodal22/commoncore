#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int a;
    char *result;

    i = 0;
    a = 0;

    while (s1[i] != '\0')
    {
        i++;
    }
    while (s2[a] != '\0')
    {
        i++;
        a++;
    }

    result = malloc((i * sizeof(char)) + 1);

    if (result == NULL)
    {
        return NULL;
    }

    i = 0;
    a = 0;

    while (s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[a] != '\0')
    {
        result[i] = s2[a];
        a++;
        i++;
    }

    result[i] = '\0';

    return (result);
}


int main()
{
    const char *str1 = "Hello, ";
    const char *str2 = "World!";
    char *result = ft_strjoin(str1, str2);

    if (result != NULL)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Falha ao alocar memória para a string concatenada.\n");
    }

    return 0;
}
