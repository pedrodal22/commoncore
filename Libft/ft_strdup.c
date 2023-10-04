#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strdup(char *src)
{
	int		b;
	char	*dup;

	b = 0;
	dup = (char *)malloc (ft_strlen(src));
	while (src[b] != '\0')
	{
		dup[b] = src[b];
		b++;
	}
	dup[b] = '\0';
	return (dup);
}

/*
int main(void)
{
	char *str = "Ola a todos";
	char *dup;

	dup = ft_strdup(str);

	printf("%s\n", dup);
	free(dup);
	printf("%s\n", dup);
	printf("...");
}
*/
