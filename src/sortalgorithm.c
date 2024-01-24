/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortalgorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:50:54 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/03 16:38:54 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	int		size;
	t_list	*head;

	head = *stack_a;
	size = ft_lstsize(head);
	if (sorted_already(stack_a) == TRUE || size <= 1)
		return ;
	else if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 15)
		mini_sort(stack_a, stack_b, size);
	else if (size <= 600)
		new_method(stack_a, stack_b);
	else if (size > 600)
		middle_sort(stack_a, stack_b, size);
	ft_lstclear(stack_a, del);
}

void	mini_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int		min;
	int		index;
	int		len;

	len = size;
	min = find_smallest(stack_a);
	index = find_index(stack_a, min);
	while (size > 3)
	{
		if (min == (*stack_a)->value)
		{
			pb(stack_a, stack_b);
			size--;
			min = find_smallest(stack_a);
			index = find_index(stack_a, min);
		}
		if (size / 2 >= index && index != 1)
			ra(stack_a);
		else if (index != 1)
			rra(stack_a);
	}
	sort_3(stack_a);
	while (len-- > 3)
		pa(stack_b, stack_a);
}

void	sort_3(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (!(sorted_already(stack)))
	{
		head = *stack;
		if (head->value < head->next->value)
			rra(stack);
		else if (head->value > head->next->value
			&& head->value < head->next->next->value)
			sa(stack);
		else if (head->value > head->next->value
			&& head->next->value > head->next->next->value)
			sa(stack);
		else
			ra(stack);
	}
}

void	swapper(t_list *first, t_list *second)
{
	int	k;

	k = first->value;
	first->value = second->value;
	second->value = k;
}

t_list	*sort_the_list(t_list *stack)
{
	t_list	*head;
	t_list	*min;
	t_list	*temp;

	head = stack;
	while (head->next)
	{
		min = head;
		temp = head->next;
		while (temp)
		{
			if (temp->value < min->value)
				min = temp;
			temp = temp->next;
		}
		swapper(head, min);
		head = head->next;
	}
	return (stack);
}
