/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:51:17 by pedro             #+#    #+#             */
/*   Updated: 2024/02/23 19:29:22 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_ptr(void *ptr)
{
	int			count;
	uintptr_t	pointer;

	pointer = (uintptr_t)ptr;
	count = 0;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_ptr_hexa(pointer);
	return (count);
}

int	ft_ptr_hexa(uintptr_t nb)
{
	int				count;
	uintptr_t		resto;

	count = 0;
	if (nb >= 16)
	{
		count += ft_ptr_hexa(nb / 16);
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
