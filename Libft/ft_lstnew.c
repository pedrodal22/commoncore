/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:44:49 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/24 13:12:04 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->content = content;
	return (node);
}

/* int main (void)
{
	t_list *ret;
	
	ret = ft_lstnew("ola");
	printf("%p\n", ret);
	if (ret)
	{	
		printf("content: %s\n", (char *) ret->content);
		printf("next: %p\n",ret->next);
	}
	free(ret);
} */