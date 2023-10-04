//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

/*
int main(void)
{
	char str[15] = "ola a todos!4";
	
	printf("%s\n", str);
	ft_strupcase(str);
	printf("%s", str);
}
*/
