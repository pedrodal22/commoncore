/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:50:58 by pfranco-          #+#    #+#             */
/*   Updated: 2023/12/26 16:50:58 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	gnl_ft()
{
	static int i;
	char buffer[BUFFER_SIZE + 1];

	if(BUFFER_SIZE <= 0)
		return(NULL);
    while (read(xx, xx, xx) > 0 )
}
