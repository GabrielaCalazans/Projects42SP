/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:01:15 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/08 00:04:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if (!(new_list))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		lst = lst->next;
	}
	new_list->next = NULL;
	return (new_list);
}
