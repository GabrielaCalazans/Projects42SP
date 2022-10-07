/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:14:28 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/07 20:57:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stddef.h>

void addOne(void * p) {++*(int*)p;}

typedef struct MY_STRUCT
{
	int	x;
	int	y;
}			t_point;

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(void)
{
	//******************** TESTE LSTNEW **************************
	// t_list * l =  ft_lstnew((void*)42);
	// /* 1 */ printf("%d\n", l->content);
	// /* 2 */ printf("%d\n", l->next);
	
	//******************** TESTE LSTNEW **************************
	// t_list * l =  NULL;
	// ft_lstadd_front(&l, ft_lstnew((void*)1));
	// /* 1 */ printf("%d\n", l->content); // == 1
	// /* 2 */ printf("%d\n", l->next); // == 0
	// ft_lstadd_front(&l, ft_lstnew((void*)2));
	// /* 3 */ printf("%d\n", l->content); // == 2
	// /* 4 */ printf("%d\n", l->next->content); // == 1
	// /* 5 */ printf("%d\n", l->next->next); // == 0
	
	//******************** TESTE LSTSIZE **************************
	// t_list * l =  NULL;
	// /* 1 */ printf("%d\n", ft_lstsize(l)); // == 0
	// ft_lstadd_front(&l, ft_lstnew((void*)1));
	// /* 2 */ printf("%d\n", ft_lstsize(l)); // == 1
	// ft_lstadd_front(&l, ft_lstnew((void*)2));
	// /* 3 */ printf("%d\n", ft_lstsize(l)); // == 2
	// free(l);
	
	//******************** TESTE LSTLAST **************************
	// t_list * l =  NULL;
	// /* 1 */ printf("%d\n", ft_lstlast(l)); // == 0
	// ft_lstadd_back(&l, ft_lstnew((void*)1));
	// /* 2 */ printf("%d\n", ft_lstlast(l)->content); // == 1
	// ft_lstadd_back(&l, ft_lstnew((void*)2));
	// /* 3 */ printf("%d\n", ft_lstlast(l)->content); // == 2
	// /* 4 */ printf("%d\n", ft_lstlast(l)->next); // == 0
	
	//******************** TESTE LSTADD_BACK **************************
	// t_list * l =  NULL; t_list * l2 =  NULL;
	// ft_lstadd_back(&l, ft_lstnew((void*)1));
	// /* 1 */ printf("%d\n", l->content); // == 1
	// /* 2 */ printf("%d\n", l->next); // == 0
	// ft_lstadd_back(&l, ft_lstnew((void*)2));
	// /* 3 */ printf("%d\n", l->content); // == 1
	// /* 4 */ printf("%d\n", l->next->content); // == 2
	// /* 5 */ printf("%d\n", l->next->next); // == 0
	// ft_lstadd_back(&l2, ft_lstnew((void*)3));
	// ft_lstadd_back(&l2, ft_lstnew((void*)4));
	// ft_lstadd_back(&l, l2);
	// /* 6 */ printf("%d\n", l->content); // == 1
	// /* 7 */ printf("%d\n", l->next->content); // == 2
	// /* 8 */ printf("%d\n", l->next->next->content); // == 3
	// /* 9 */ printf("%d\n", l->next->next->next->content); // == 4
	// /* 10 */ printf("%d\n", l->next->next->next->next); // == 0
	
	//******************** TESTE LSTDELONE **************************
	// t_list * l =  ft_lstnew(malloc(1));
	// ft_lstdelone(l, free); l = 0;
	// printf("%i\n", l);

	//******************** TESTE LSTCLEAR **************************
	// t_list * l =  ft_lstnew(malloc(1));
	// for (int i = 0; i < 10; ++i)
	// ft_lstadd_front(&l, ft_lstnew(malloc(1)));
	// ft_lstclear(&l, free);
	// /* 1 */ printf("%d", l);

	//******************** TESTE LSTITER **************************
	// int tab[] = {0, 1, 2, 3};
	// t_list * l =  ft_lstnew(tab);
	// for (int i = 1; i < 4; ++i)
	// ft_lstadd_back(&l, ft_lstnew(tab + i));
	// ft_lstiter(l, addOne);
	// t_list * tmp = l;
	// /* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	// {
	// 	printf("%d", l);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	//******************** TESTE LSTMAP **************************
	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list * m = ft_lstmap(l, addOne, free);
	t_list * tmp = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int*)tmp->content == i);
		tmp = tmp->next;
	}
	tmp = m;
	/* 5 6 7 8 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int*)tmp->content == i + 1);
		tmp = tmp->next;
	}
	freeList(l); ft_lstclear(&m, free);
	
	return (0);
}
