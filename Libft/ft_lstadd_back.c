/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:44:49 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/24 13:17:53 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (tmp == NULL)
		*lst = new;
	else
		tmp->next = new;
}
/* 
int main (void)
{
	t_list *ret;
	t_list *tmp;


	ret = NULL;
	ft_lstadd_back(&ret,ft_lstnew("5"));
	ft_lstadd_back(&ret, ft_lstnew("9"));
	while (ret)
	{	
		printf("%s\n", (char *)ret->content);
		tmp = ret->next;
		free(ret);
		ret = tmp;
	}
}  */ 