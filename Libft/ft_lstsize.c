/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:44:49 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:44 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* int main (void)
{
	t_list *ret;
	t_list *tmp;

	
	ret = ft_lstnew("5");
	
	ft_lstadd_front(&ret, ft_lstnew("9"));
	printf("size: %i\n", ft_lstsize(ret));
	while (ret)
	{	
		printf("%s\n", (char *)ret->content);
		tmp = ret->next;
		free(ret);
		ret = tmp;
	}
} */