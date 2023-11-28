/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:30:33 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:09 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/* int main (void)
{
	t_list *ret;
	t_list *tmp;

	
	ret = ft_lstnew("5");
	
	ft_lstadd_front(&ret, ft_lstnew("9"));
	printf("size: %i\n", ft_lstsize(ret));
	printf("last: %s\n", (char *) ft_lstlast(ret)->content);
	while (ret)
	{	
		printf("%s\n", (char *)ret->content);
		tmp = ret->next;
		free(ret);
		ret = tmp;
	}
} */