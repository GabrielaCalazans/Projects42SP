/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:55:11 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/08 00:01:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst && del)
	{
		while (lst)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			free (*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}
