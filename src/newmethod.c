/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmethod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:18:21 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/04 12:48:02 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	new_method(t_list **stack_a, t_list **stack_b)
{

	nm_pivoting(stack_a, stack_b);
	mini_sort(stack_a, stack_b, ft_lstsize(*stack_a));
	nmb_pivoting_rrb(stack_a, stack_b, 440);
}


int	pivot_finder(t_list **stack)
{

	t_list	*head;
	t_list	*sorted_list;
	int		size;
	int		pivot;

	size = ft_lstsize(*stack);
	head = dup_list(*stack);
	sorted_list = sort_the_list(head);
	pivot = order_pivot(sorted_list, size / 2);
	ft_lstclear(&sorted_list, del);
	return pivot;
}

int	b_pivot_finder(t_list **stack, int size)
{

	t_list	*head;
	t_list	*sorted_list;
	int		pivot;

	head = dup_list(*stack);
	sorted_list = sort_the_list(head);
	pivot = order_pivot(sorted_list, size);
	ft_lstclear(&sorted_list, del);
	return pivot;
}

void	nmb_pivoting(t_list **stack_a, t_list **stack_b, int size)
{
	int	pivot;

	if (ft_lstsize(*stack_b) == 250)
		return ;
	pivot = b_pivot_finder(stack_b, size);
	while (b_check_if_any_nums_left(*stack_b, pivot))
	{
		if ((*stack_b)->value >= pivot)
		{
			pa(stack_b, stack_a);
		}
		else
			rb(stack_b);
	}
	nmb_pivoting_rrb(stack_a, stack_b, ft_lstsize(*stack_b) - 60);
}

void	nmb_pivoting_rrb(t_list **stack_a, t_list **stack_b, int size)
{
	int	pivot;

	if (ft_lstsize(*stack_b) == 250)
		return ;
	pivot = b_pivot_finder(stack_b, size);
	while (b_check_if_any_nums_left(*stack_b, pivot))
	{
		if ((*stack_b)->value >= pivot)
		{
			pa(stack_a, stack_b);
		}
		else if(index_pivotable(stack_b, pivot))
			rb(stack_b);
			
		else
			rrb(stack_b);
	}
	nmb_pivoting_rrb(stack_a, stack_b, ft_lstsize(*stack_b) - 60);
}

void	nm_pivoting(t_list **stack_a, t_list **stack_b)
{
	int	pivot;
	pivot = pivot_finder(stack_a);

	if (ft_lstsize(*stack_a) < 60)
		return ;
	while (check_if_any_nums_left(*stack_a, pivot))
	{
		if ((*stack_a)->value <= pivot)
		{
			pb(stack_b, stack_a);
		}
		else
			ra(stack_a);
	}
	nm_pivoting(stack_a, stack_b);
}

int    check_if_any_nums_left(t_list *stack_a, int pivot)
{
    t_list  *head;
    head = (stack_a);
    while (head != NULL)
    {
        if (head->value <= pivot)
            return (TRUE);
        head = head->next;
    }
    return (FALSE);
}

int    b_check_if_any_nums_left(t_list *stack_a, int pivot)
{
    t_list  *head;
    head = (stack_a);
    while (head != NULL)
    {
        if (head->value >= pivot)
            return (TRUE);
        head = head->next;
    }
    return (FALSE);
}

int	index_pivotable(t_list **stack, int pivot)
{
	t_list *head;
	int		i;
	int		j;

	i = 0;
	j = 0;
	head = *stack;
	while (head)
	{
		if (head->value >= pivot)
			break ;
		i++;
		head = head->next;
	}
	while (head)
	{
		if (head->value >= pivot)
			break ;
		j++;
		traverseBackward(head);
	}
	if (i > j)
		return TRUE;
	else
		return FALSE;
}

void traverseBackward(t_list *head) 
{
    if (head == NULL)
        return;
    traverseBackward(head->next);
}
