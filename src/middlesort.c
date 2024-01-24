/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:19:04 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/02 13:27:27 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	middle_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head;
	t_list	*sorted_list;
	int		len;

	head = dup_list(*stack_a);
	sorted_list = sort_the_list(head);
	a_pivotted(stack_a, stack_b, order_pivot(sorted_list, 16 * size / 32));
	a_pivotted(stack_a, stack_b, order_pivot(sorted_list, 24 * size / 32));
	a_pivotted(stack_a, stack_b, order_pivot(sorted_list, 28 * size / 32));
	a_pivotted(stack_a, stack_b, order_pivot(sorted_list, 29 * size / 32));
	a_pivotted(stack_a, stack_b, order_pivot(sorted_list, 30 * size / 32));
	a_pivotted(stack_a, stack_b, order_pivot(sorted_list, 31 * size / 32));
	len = ft_lstsize(*stack_a);
	mini_sort(stack_a, stack_b, len);
	middle_pivot_rb(stack_a, stack_b, order_pivot(sorted_list, 24 * size / 32),
		order_pivot(sorted_list, 24 * size / 32));
	middle_pivot_rb(stack_a, stack_b, order_pivot(sorted_list, 20 * size / 32),
		order_pivot(sorted_list, 16 * size / 32));
	middle_pivotdeneme_rrb(stack_a, stack_b,
		order_pivot(sorted_list, 16 * size / 32));
	b_pivotted(stack_a, stack_b, order_pivot(sorted_list, 12 * size / 32));
	b_pivotted(stack_a, stack_b, order_pivot(sorted_list, 8 * size / 32));
	b_pivotted(stack_a, stack_b, order_pivot(sorted_list, 4 * size / 32));
	b_pivotted(stack_a, stack_b, order_pivot(sorted_list, 0 * size / 32));
	middle_sort2(stack_a, stack_b, sorted_list, size);
}

void	middle_sort2(t_list **stack_a, t_list **stack_b,
	t_list *sorted_list, int size)
{
	int		i;
	int		k;
	int		s;

	k = 0;
	s = size / 32 - k;
	i = 4;
	while (i < 32)
	{
		if (i == 28)
			k = 1;
		else
			k = 0;
		middle_pivot_ra(stack_a, stack_b, order_pivot(sorted_list,
				(i - 3) * size / 32), order_pivot(sorted_list, i * size / 32));
		middle_pivot_rra(stack_a, stack_b, order_pivot(sorted_list,
				(i - 2) * size / 32), order_pivot(sorted_list, (i + 4) * s));
		middle_pivot_ra(stack_a, stack_b, order_pivot(sorted_list,
				(i - 1) * size / 32), order_pivot(sorted_list, i * size / 32));
		middle_pivot_rra(stack_a, stack_b, order_pivot(sorted_list,
				i * size / 32), order_pivot(sorted_list, (i + 4) * s));
		i += 4;
	}
	middle_sort3(stack_a, stack_b, sorted_list, size);
}

void	middle_sort3(t_list **stack_a, t_list **stack_b,
	t_list *sorted_list, int size)
{
	middle_pivot_ra(stack_a, stack_b, order_pivot(sorted_list, 29 * size / 32),
		order_pivot(sorted_list, 30 * size / 32));
	middle_pivot_rra(stack_a, stack_b, order_pivot(sorted_list, 30 * size / 32),
		order_pivot(sorted_list, 32 * size / 32 - 1));
	middle_pivot_ra(stack_a, stack_b, order_pivot(sorted_list, 31 * size / 32),
		order_pivot(sorted_list, 31 * size / 32));
	last_sort_3(stack_a, stack_b, size);
	pa(stack_b, stack_a);
	ft_lstclear(&sorted_list, del);
}
