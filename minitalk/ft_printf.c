/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:35 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 12:52:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char )c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

int	ft_conv(char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		ft_putchar(va_arg(args, int));
	if (str[i] == 'i' || str[i] == 'd')
		ft_putnbr(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, str);
	if (str == NULL || str[0] == '\0')
	{
		va_end (args);
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("csdiupxX%", str[i + 1]) != NULL)
		{
			ft_conv((char *)str, i + 1, args);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (count);
}

/* int main(void)
{

    printf("Expected output:   %i", 23425);
    ft_printf("Testing ft_printf: %i\n", 23425);
    return 0;
}  */