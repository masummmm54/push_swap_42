/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:33:06 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/03 16:09:16 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_100(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head;
	int		*pivot;
	int		len;

	len = size;
	head = dup_list(*stack_a);
	pivot = get_pivot(head, size);
	head = *stack_b;
	a_pivotted(stack_a, stack_b, pivot[9] - 1);
	a_pivotted(stack_a, stack_b, pivot[12] - 1);
	a_pivotted(stack_a, stack_b, pivot[15] - 1);
	a_pivotted(stack_a, stack_b, pivot[17] - 1);
	len = ft_lstsize(*stack_a);
	mini_sort(stack_a, stack_b, len);
	last_sort_100(stack_a, stack_b, 8 * size / 20 - 1);
	b_pivotted(stack_a, stack_b, pivot[4]);
	b_pivotted(stack_a, stack_b, pivot[2]);
	middle_pivot_ra(stack_a, stack_b, pivot[4], pivot[4] + 1);
	middle_pivot_ra(stack_a, stack_b, pivot[6], pivot[9] + 1);
	middle_pivot_rra(stack_a, stack_b, pivot[8], pivot[10]);
	middle_pivot_ra(stack_a, stack_b, pivot[9], pivot[9]);
	last_sort_100(stack_a, stack_b, size);
	pa(stack_b, stack_a);
	free(pivot);
}

void	last_sort_100(t_list **stack_a, t_list **stack_b, int i)
{
	int		big;
	int		size;
	int		index;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	size = ft_lstsize(*stack_b);
	big = find_biggest(stack_b);
	index = find_index(stack_b, big);
	while ((*stack_b)->next && i != 0)
	{
		if (big == (*stack_b)->value)
		{
			pa(stack_b, stack_a);
			big = find_biggest(stack_b);
			index = find_index(stack_b, big);
			size--;
			i--;
		}
		if (size / 2 >= index && index != 1 && *stack_b)
			rb(stack_b);
		else if (index != 1 && *stack_b)
			rrb(stack_b);
	}
}
