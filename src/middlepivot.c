/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middlepivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:11:01 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/02 12:06:04 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	middle_pivot_rb(t_list **stack_a, t_list **stack_b,
	int pivot, int firstorder)
{
	t_list	*head;

	head = *stack_b;
	while (head->value > firstorder && head != NULL)
	{
		if (head->value >= pivot)
		{
			pa(stack_b, stack_a);
		}
		else
			rb(stack_b);
		head = *stack_b;
	}
}

void	middle_pivot_rrb(t_list **stack_a, t_list **stack_b,
	int pivot, int firstorder)
{
	t_list	*head;

	head = *stack_b;
	while (head->value >= firstorder && head)
	{
		if (head->value >= pivot)
		{
			pa(stack_b, stack_a);
		}
		else
			rrb(stack_b);
		head = *stack_b;
	}
	rb(stack_b);
}

void	middle_pivotdeneme_rrb(t_list **stack_a, t_list **stack_b, int pivot)
{
	t_list	*head;

	while (1)
	{
		rrb(stack_b);
		head = *stack_b;
		if (head->value >= pivot)
		{
			pa(stack_b, stack_a);
		}
		else
			break ;
	}
}

void	middle_pivot_ra(t_list **stack_a, t_list **stack_b,
	int pivot, int firstorder)
{
	t_list	*head;

	head = *stack_a;
	while (head->value <= firstorder)
	{
		if (head->value <= pivot)
		{
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
		head = *stack_a;
	}
}

void	middle_pivot_rra(t_list **stack_a, t_list **stack_b,
	int pivot, int firstorder)
{
	t_list	*head;

	head = *stack_a;
	while (head->value < firstorder)
	{
		if (head->value <= pivot)
		{
			pb(stack_a, stack_b);
		}
		else
			rra(stack_a);
		head = *stack_a;
	}
	ra(stack_a);
}
