/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:44:49 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/24 13:17:27 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
		(*del)(lst->content);
	free (lst);
}

/* void del(void *v)
{	
	printf("del: %s\n", (char *) v);
}

int main (void)
{
	t_list *ret;
	t_list *tmp;


	ret = NULL;
	ft_lstadd_back(&ret,ft_lstnew("5"));
	ft_lstadd_back(&ret, ft_lstnew("9"));
	while (ret)
	{	
		tmp = ret->next;
		ft_lstdelone(ret, del); 
		ret = tmp;
	}
}    */