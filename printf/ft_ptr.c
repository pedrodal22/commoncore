/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:30:41 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 19:30:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	count += ft_hexa(pointer);
	return (count);
}
