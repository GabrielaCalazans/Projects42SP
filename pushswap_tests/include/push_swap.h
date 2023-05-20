/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/20 19:49:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

// dealing list
t_stack	*nodenew(int data);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_prevlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int	ft_lstsize(t_stack *lst);

// moves
void	ft_swap(t_stack *head, int check);
void	ft_push(t_stack *a_head, t_stack *b_head, int check);
void	ft_rotate(t_stack *head, int check);
void	ft_rotate(t_stack *head, int check);


#endif
