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

int	ft_hexa(unsigned int nb)
{
	int				count;
	unsigned int	resto;

	count = 0;
	if (nb >= 16)
	{
		count += ft_hexa(nb / 16);
		resto = nb % 16;
		if (resto < 10)
			count += ft_putchar(resto + 48);
		else
			count += ft_putchar(resto - 10 + 'a');
	}
	else
	{
		if (nb < 10)
			count += ft_putchar(nb + '0');
		else
			count += ft_putchar(nb - 10 + 'a');
	}
	return (count);
}
