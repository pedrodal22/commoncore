/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:35:50 by pfranco-          #+#    #+#             */
/*   Updated: 2024/02/14 15:34:53 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (str[a])
	{
		count += ft_putchar(str[a]);
		a++;
	}
	return (count);
}