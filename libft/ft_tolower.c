#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 'Z' && str[i] >= 'A'))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*
int main(void)
{
	char str[15] = "OLA  todos!4";
	
	printf("%s\n", str);
	ft_strlowcase(str);
	printf("%s", str);
}
*/