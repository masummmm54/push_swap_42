/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babasort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:05:24 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/05 16:17:12 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_pivotted(t_list **stack_a, t_list **stack_b, int pivot)
{
	t_list	*head;
	int		size;

	head = *stack_a;
	size = ft_lstsize(*stack_a);
	while (size != 0 && head != NULL)
	{
		head = *stack_a;
		if (head->value <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		size--;
	}
}

void	b_pivotted(t_list **stack_a, t_list **stack_b, int pivot)
{
	t_list	*head;
	int		size;

	size = ft_lstsize(*stack_b);
	while (size != 0 && head != NULL)
	{
		head = *stack_b;
		if (head->value >= pivot)
			pa(stack_b, stack_a);
		else
			rb(stack_b);
		size--;
	}
}

void	last_sort_3(t_list **stack_a, t_list **stack_b, int i)
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
		else if (size / 2 >= index && index != 1 && *stack_b && i != 0 )
			rb(stack_b);
		else if (index != 1 && *stack_b && i != 0)
			rrb(stack_b);
	}
}
 