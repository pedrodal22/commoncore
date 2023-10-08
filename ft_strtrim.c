#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char *s1, const char *set)
{
	int	i;
	int	p;
	int	temp;
	int size = strlen(set);

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[p])
		{
			temp = tab[i];
			tab[i] = tab[p];
			tab[p] = temp;
		}
		p++;
	}
}

/*
char	*ft_strtrim(char *s1, const char *set)
{
	int	i;
	int start;
	int end;
	char *final;
	int size;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	size = end - start + 1;
	while(s1[start] == *set)
	{
		start++;
	}
	while(s1[end] == *set)
	{
		end--;
	}
	final = malloc(end - start + 2);
	while(i < size && start < end)
	{
		final[i] = s1[start];
		i++;
		start++;
	}
	final[i] = '\0';
	return(final);
}


int main() {
    char str[] = "ghrOlá,kk Mugndo!grsdgg";
    char set[] = "ghr";

    char *resultado = ft_strtrim(str, set);

    if (resultado != NULL) {
        printf("String resultante: '%s'\n", resultado);
        free(resultado); // Não se esqueça de liberar a memória alocada
    } else {
        printf("Erro na alocação de memória.\n");
    }

    return 0;
}
*/