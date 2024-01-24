/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:30:36 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/17 12:07:06 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include "ft_libft/libft.h"
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	r_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	push(t_list **stack_1, t_list **stack_2);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);

void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_b);
void	sa(t_list **stack_a);


int		pivot_finder(t_list **stack);
int		b_pivot_finder(t_list **stack, int size);
void	new_method(t_list **stack_a, t_list **stack_b);
int		check_if_any_nums_left(t_list *stack_a, int pivot);
int		b_check_if_any_nums_left(t_list *stack_a, int pivot);
void	nm_pivoting(t_list **stack_a, t_list **stack_b);
void	nmb_pivoting(t_list **stack_a, t_list **stack_b, int size);
void	nmb_pivoting_rrb(t_list **stack_a, t_list **stack_b, int size);
int		index_pivotable(t_list **stack, int pivot);
void	traverseBackward(t_list *head);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstbeforelast(t_list *lst);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);
void	del(int *value);
void	ft_lstdelone(t_list *lst, void (*del)(int *));
void	ft_lstclear(t_list **lst, void (*del)(int *));

void	sort_list(t_list **stack_a, t_list **stack_b);
int		find_smallest(t_list **stack);
int		find_biggest(t_list **stack);
int		find_index(t_list **stack, int num);

void	sort_100(t_list **stack_a, t_list **stack_b, int size);
void	last_sort_100(t_list **stack_a, t_list **stack_b, int i);

void	middle_sort(t_list **stack_a, t_list **stack_b, int size);
void	middle_sort2(t_list **stack_a, t_list **stack_b,
			t_list *sorted_list, int size);
void	middle_sort3(t_list **stack_a, t_list **stack_b,
			t_list *sorted_list, int size);
void	a_pivotted(t_list **stack_a, t_list **stack_b, int pivot);
void	b_pivotted(t_list **stack_a, t_list **stack_b, int pivot);
void	middle_pivotdeneme_rrb(t_list **stack_a, t_list **stack_b, int pivot);
void	middle_pivot_rb(t_list **stack_a, t_list **stack_b,
			int pivot, int firstorder);
void	middle_pivot_rrb(t_list **stack_a, t_list **stack_b,
			int pivot, int firstorder);
void	middle_pivot_ra(t_list **stack_a, t_list **stack_b,
			int pivot, int firstorder);
void	middle_pivot_rra(t_list **stack_a, t_list **stack_b,
			int pivot, int firstorder);
void	last_sort_3(t_list **stack_a, t_list **stack_b, int i);

int		*get_pivot(t_list *fstack, int size);
int		order_pivot(t_list *head, int nbr);

void	mini_sort(t_list **stack_a, t_list **stack_b, int size);
void	sort_3(t_list **stack);
void	swapper(t_list *first, t_list *second);
t_list	*sort_the_list(t_list *stack);
t_list	*dup_list(t_list *stack);

int		check_errors(char **av);
int		check_numbers(int num, char **av);
int		ft_isdigit(int c);
int		sorted_already(t_list **stack);
char	**free_array(size_t i, char **array);

#endif