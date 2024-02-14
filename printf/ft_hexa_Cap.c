/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:21:37 by marvin            #+#    #+#             */
/*   Updated: 2023/11/28 20:21:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexa_Cap (long long int nb)
{
    int count;
    long long int resto;

    count = 0;
    if (!nb)
        return (0);
    if (nb < 0)
    {
        count += ft_putchar('-');
        nb *= -1;
    }
    if (nb >= 16)
    {
        count += ft_hexa_Cap(nb / 16);
        resto = nb % 16;
        if(resto < 10)
            count += ft_putchar(resto + 48);
        else
            count += ft_putchar(resto - 10 + 'A');
        
    }
    else
        if (nb < 10)
            count += ft_putchar(nb + '0');
        else
            count += ft_putchar(nb - 10 + 'A');
    return (count);
}