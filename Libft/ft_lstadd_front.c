/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:44:49 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/24 13:12:23 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new; 
}

/* int main (void)
{
	t_list *ret;
	t_list *tmp;

	
	ret = ft_lstnew("5");
	
	ft_lstadd_front(&ret, ft_lstnew("9"));
	while (ret)
	{	
		printf("%s\n", (char *)ret->content);
		tmp = ret->next;
		free(ret);
		ret = tmp;
	}
}  */