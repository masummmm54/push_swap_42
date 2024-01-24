/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:04:18 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/02 12:55:24 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*dup_list(t_list *stack)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*head;

	temp2 = NULL;
	head = stack;
	while (head)
	{
		temp = ft_lstnew(head->value);
		ft_lstadd_back(&temp2, temp);
		head = head->next;
	}
	return (temp2);
}

int	find_biggest(t_list **stack)
{
	int		big;
	t_list	*head;

	if ((*stack) == NULL || stack == NULL)
		return (0);
	head = *stack;
	big = head->value;
	while (head)
	{
		if (big < head->value)
			big = head->value;
		head = head->next;
	}
	return (big);
}

int	*get_pivot(t_list *fstack, int size)
{
	t_list	*head;
	int		nbrpivots;
	int		*pivot;
	int		i;

	i = 0;
	nbrpivots = 0;
	pivot = (int *)malloc(sizeof(int) * 20);
	head = sort_the_list(fstack);
	while (i < 19)
	{
		nbrpivots += size / 20;
		pivot[i] = order_pivot(head, nbrpivots);
		i++;
	}
	ft_lstclear(&head, del);
	return (pivot);
}

int	order_pivot(t_list *head, int nbr)
{
	int	pivot;

	pivot = 0;
	while (nbr != 0)
	{
		head = head->next;
		nbr--;
	}
	pivot = head->value;
	return (pivot);
}
