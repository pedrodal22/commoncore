/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:12:17 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/28 10:01:56 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*i;

	new_list = NULL;
	while (lst && f && del)
	{
		i = f(lst->content);
		new_node = ft_lstnew(i);
		if (!new_node || !i)
		{
			ft_lstclear(&new_list, del);
			if (new_node)
				free(new_node);
			if (i)
				del(i);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
