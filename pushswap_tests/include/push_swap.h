/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/24 16:30:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
#include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

// dealing list
t_stack	*createnode(int data);
t_stack	*ft_last(t_stack *lst);
t_stack	*ft_prevlast(t_stack *lst);
void	ft_add_front(t_stack **lst, t_stack *new);
void	ft_add_back(t_stack **lst, t_stack *new);
int		ft_size(t_stack *lst);
void	ft_clear(t_stack **lst);

// moves
void	ft_swap_ab(t_stack **head, int check);
void	ft_swap_ss(t_stack **a_head, t_stack **b_head, int check);
void	ft_push_a(t_stack **a_head, t_stack **b_head, int check);
void	ft_push_b(t_stack **a_head, t_stack **b_head, int check);
void	ft_rotate_ab(t_stack **head, int check);
void	ft_rotate_rr(t_stack **a_head, t_stack **b_head, int check);
void	ft_rev_rotate_ab(t_stack **head, int check);
void	ft_rev_rotate_r(t_stack **a_head, t_stack **b_head, int check);

t_stack	*starting_a(t_stack	**a, int argc, char *argv[]);
void	sortingit(t_stack **a, t_stack	**b);
int		check_args(int argc, char *argv[]);
int		ft_atoi_error(const char *nptr);
void	ft_puterror(void);
void	freearray(char **array);

void	printlist(t_stack *head);

#endif
