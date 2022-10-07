/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:33:30 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/05 20:24:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstnew(void *content)
{
	t_list	*newptr;

	*newptr = (t_list *)malloc(sizeof(t_list));
	*newptr->content = content;//== (*newptr).content = content
	newptr->next = NULL;
	return (newptr);
}
