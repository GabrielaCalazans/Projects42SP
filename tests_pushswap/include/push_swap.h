/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/02 17:38:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

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
void	ft_rotate_ab(t_stack **head, int check);
void	ft_rotate_rr(t_stack **a_head, t_stack **b_head, int check);
void	ft_rev_rotate_ab(t_stack **head, int check);
void	ft_rev_rotate_r(t_stack **a_head, t_stack **b_head, int check);

// Moves
void	do_rot_a(t_stack **a, int rot_nbr, int check_rot);
void	do_rot_b(t_stack **b, int rot_nbr, int check_rot);
void	do_rot_ab(t_stack **a, t_stack **b, int rot_nbr, int check_rot);
// int		do_single_rot_atob(t_stack **a, t_stack **b, int check);
// int		do_double_revrot_atob(t_stack **a, t_stack **b, int check);
// int		do_rota_revrotb(t_stack **a, t_stack **b, int check);
// int		do_rotb_revrota(t_stack **a, t_stack **b, int check);

int		do_rr(t_stack **a, t_stack **b, int check, int stack);
int		do_rrr(t_stack **a, t_stack **b, int check, int stack);
int		do_ra_rrb(t_stack **a, t_stack **b, int check, int stack);
int		do_rb_rra(t_stack **a, t_stack **b, int check, int stack);

t_stack	*starting(t_stack **a, int argc, char *argv[]);
void	sorting_it(t_stack **a, t_stack **b, int len);
// void	sort_uptosix(t_stack **a, t_stack **b, int size);
// void	sort_big_a(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **a, int check);
void	sort_three_b(t_stack **b, int check);
void	sort_five(t_stack **a, t_stack **b, int size);
void	sort_five2(t_stack **a, t_stack **b, int size);
void	sort_five_push_count(t_stack **a, t_stack **b, int size_a);
// void	quick_sort(t_stack **a, t_stack **b, int size);
void	push_all_b_to_a(t_stack **a, t_stack **b);
void	push_all_b_to_a(t_stack **a, t_stack **b);
void	push_half_to_b(t_stack **a, t_stack **b, int size);
// void	ft_sort_hundred(t_stack **a, t_stack **b, int size);
void	sort_hundre_first(t_stack **a, t_stack **b, int size_init);
void	sort_hundred_second(t_stack **a, t_stack **b, int size_init);
// void	ft_sort_b(t_stack **b);
void	ft_sort_b(t_stack **b, int size);
void	ft_sort_a(t_stack **a, int size);
void	ft_checkandpush(t_stack **a, t_stack **b);

void	sort_hundred_a_to_b(t_stack **a, t_stack **b);
void	check_and_push_to_b(t_stack **a, t_stack **b);
void	check_and_push_to_a(t_stack **a, t_stack **b);
void	sort_final(t_stack **a, int len);
void	sort_hundred(t_stack **a, t_stack **b, int len);

int		check_args(int argc, char *argv[]);
int		check_error(char *argv[], int i, int j);
void	check_int(char *argv[]);
int		ft_checkdup(char **str, int i);
int		check_its_sorted_a(t_stack **a);
int		check_its_sorted_b(t_stack **b);
int		check_its_sorted_a_len(t_stack **a);
int		check_its_sorted_b_len(t_stack **b);
int		check_its_sorted_a_idx(t_stack **a);
int		check_its_sorted_b_idx(t_stack **b);
// int		check_double_rot(t_stack **a, t_stack **b, );
// int		check_rot_a(t_stack **a, int check_a);
// int		check_rot_b(t_stack **b, int check_b);
int		track_pos_a(t_stack *a, int check);
int		track_pos_b(t_stack *b, int check);
int		check_op_a_to_b(t_stack *a, t_stack *b);
int		check_op_b_to_a(t_stack *a, t_stack *b);
int		rate_rr_atob(t_stack *a, t_stack *b, int check);
int		rate_rrr_atob(t_stack *a, t_stack *b, int check);
int		rate_ra_rrb_atob(t_stack *a, t_stack *b, int check);
int		rate_rb_rra_atob(t_stack *a, t_stack *b, int check);
void	check_and_push_to_b(t_stack **a, t_stack **b);
int		rate_rr_btoa(t_stack *a, t_stack *b, int check);
int		rate_rrr_btoa(t_stack *a, t_stack *b, int check);
int		rate_ra_rrb_btoa(t_stack *a, t_stack *b, int check);
int		rate_rb_rra_btoa(t_stack *a, t_stack *b, int check);

void	printlist(t_stack *head);

int		ft_max(t_stack *head);
int		ft_min(t_stack *head);
int		ft_min_size(t_stack *head, int size, char check);
int		ft_max_size(t_stack *head, int size, char check);
int		ft_sec_min(t_stack *head);
int		ft_int_pos(t_stack *head, int pos);
int		ft_int_pos1(t_stack *head, int find);
int		ft_int_pos2(t_stack *head, int find);
void	ft_freearray(char **array);
void	ft_puterror(void);
int		ft_atoi_error(const char *nptr);
void	push_size_of_b_to_a(t_stack **a, t_stack **b, int size);

#endif
