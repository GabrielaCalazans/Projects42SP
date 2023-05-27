/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/26 22:22:10 by gacalaza         ###   ########.fr       */
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

// Instructions
void	ft_swap_ab(t_stack **head, int check);
void	ft_swap_ss(t_stack **a_head, t_stack **b_head, int check);
void	ft_push_a(t_stack **a_head, t_stack **b_head, int check);
void	ft_push_b(t_stack **a_head, t_stack **b_head, int check);
void	ft_rotate_ab(t_stack **head, int check);
void	ft_rotate_rr(t_stack **a_head, t_stack **b_head, int check);
void	ft_rev_rotate_ab(t_stack **head, int check);
void	ft_rev_rotate_r(t_stack **a_head, t_stack **b_head, int check);

t_stack	*starting(t_stack **a, int argc, char *argv[]);
void	sorting_it(t_stack **a, t_stack	**b, int len);
void	sort_uptosix(t_stack **a);
void	sort_three(t_stack **a);

int		check_args(int argc, char *argv[]);
int		ft_checkdup(char **str, int i);
int		checksorted(t_stack *a);
void	printlist(t_stack *head);

int		ft_max(t_stack *head);
int		ft_min(t_stack *head);
void	ft_freearray(char **array);
void	ft_puterror(void);
int		ft_atoi_error(const char *nptr);
#endif
