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

#include "../so_long.h"

int	ft_conv(char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
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
		if (str[i] == '%' && ft_strchr("csdi%", str[i + 1]) != NULL)
		{
			count += ft_conv((char *)str, i + 1, args);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (count);
}
