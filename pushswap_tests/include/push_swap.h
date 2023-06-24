/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/24 13:59:29 by gacalaza         ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// dealing list
t_stack	*createnode(int nbr, int index);
t_stack	*ft_last(t_stack *lst);
t_stack	*ft_prevlast(t_stack *lst);
t_stack	*ft_second(t_stack *lst);
void	ft_add_front(t_stack **lst, t_stack *new);
void	ft_add_back(t_stack **lst, t_stack *new);
int		ft_size(t_stack *lst);
void	ft_clear(t_stack **lst);

// Instructions
void	ft_swap_ab(t_stack **head, int check);
void	ft_swap_ss(t_stack **a_head, t_stack **b_head, int check);
void	ft_push_a(t_stack **a_head, t_stack **b_head, int check);
void	ft_push_b(t_stack **a_head, t_stack **b_head, int check);
void	ft_rotate_ab(t_stack **head, int ch97eck);
void	ft_rotate_rr(t_stack **a_head, t_stack **b_head, int check);
void	ft_rev_rotate_ab(t_stack **head, int check);
void	ft_rev_rotate_r(t_stack **a_head, t_stack **b_head, int check);

t_stack	*starting(t_stack **a, int argc, char *argv[]);
void	sorting_it(t_stack **a, t_stack **b, int len);
// void	sort_uptosix(t_stack **a, t_stack **b, int size);
// void	sort_big_a(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **head, int check);
void	sort_five(t_stack **a, t_stack **b, int size);
void	sort_five2(t_stack **a, t_stack **b, int size);
void	sort_five_push_count(t_stack **a, t_stack **b, int size_a);
// void	quick_sort(t_stack **a, t_stack **b, int size);
void	push_all_b_to_a(t_stack **a, t_stack **b);
void	push_all_b_to_a(t_stack **a, t_stack **b);
void	push_half_to_b(t_stack **a, t_stack **b, int size);
// void	ft_sort_hundred(t_stack **a, t_stack **b, int size);
void	ft_sort_hundre_first(t_stack **a, t_stack **b, int size_init);
void	ft_sort_hundred_second(t_stack **a, t_stack **b, int size_init);
// void	ft_sort_b(t_stack **b);
void	ft_sort_b(t_stack **b, int size);
void	ft_sort_a(t_stack **a, int size);
void	ft_checkandpush(t_stack **a, t_stack **b);

int		check_args(int argc, char *argv[]);
int		check_error(char *argv[], int i, int j);
void	check_int(char *argv[]);
int		ft_checkdup(char **str, int i);
int		check_its_sorted_a(t_stack **a);
int		check_its_sorted_b(t_stack **b);
int		check_its_sorted_a_len(t_stack **a);
int		check_its_sorted_a_idx(t_stack **a);
int		check_its_sorted_b_idx(t_stack **b);
int		check_its_sorted_b_len(t_stack **b);

void	printlist(t_stack *head);

int		ft_max(t_stack *head);
int		ft_min(t_stack *head);
int		ft_min_size(t_stack *head, int size, char check);
int		ft_max_size(t_stack *head, int size, char check);
int		ft_sec_min(t_stack *head);
int		ft_int_pos(t_stack *head, int pos);
void	ft_freearray(char **array);
void	ft_puterror(void);
int		ft_atoi_error(const char *nptr);
void	push_size_of_b_to_a(t_stack **a, t_stack **b, int size);

#endif
