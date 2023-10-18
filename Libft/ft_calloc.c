/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:58:17 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 18:22:20 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*ptr;
	unsigned int	total_size;

	total_size = nitems * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
	{
		memset (ptr, 0, total_size);
	}
	return (ptr);
}

/*
int main() {
    int* int_ptr = (int*)ft_calloc(15, sizeof(int));

    if (int_ptr != NULL) {
        for (int i = 0; i < 10; i++) {
            printf("%d ", int_ptr[i]);
        }
        free(int_ptr);
    } else {
        printf("Falha na alocação de memória.\n");
    }

    return 0;
}
*/
