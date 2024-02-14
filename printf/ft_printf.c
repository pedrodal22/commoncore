
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

#include "ft_printf.h"

void ft_conv(char *str, int i, va_list args)
{
	if (str[i] == 'c')
        ft_putchar(va_arg(args, int));
    else if  (str[i] == 's')
        ft_putstr(va_arg(args, const char *));
    else if (str[i] == 'd' || str[i] == 'i') 
        ft_putnbr(va_arg(args, unsigned int));
    else if (str[i] == 'p')
        ft_ptr(va_arg(args, void *));
    else if (str[i] == 'u')
        ft_unsint(va_arg(args, unsigned int));
    else if(str[i] == 'x')
        ft_hexa(va_arg(args, unsigned int));
    else if(str[i] == 'X')
        ft_hexa_Cap(va_arg(args, unsigned int));
    else if(str[i] == '%')
        ft_putchar('%');
}

int ft_printf(const char *str, ...)
{
    int i;
    va_list args;
    va_start(args, str);

    i = 0;
    if(str == NULL || str[0] == '\0')
    {
        va_end(args);
		return (0);
    }
    while(str[i] != '\0')
    {
        if(str[i] == '%' && strchr("csdiupxX%", str[i + 1]) != NULL)
        {
            ft_conv((char *)str, i + 1, args);
            i++;
        }
        else
            ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return(0);
}

int main(void)
{
    char chr = 'A';

    printf("Expected output:   %c %p %i %p.\n", chr, chr, 1353, (void *)255105);
    ft_printf("Testing ft_printf: %c %p %i %p.\n", chr, chr, 1353, 255105);
    return 0;
}
