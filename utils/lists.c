/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:38:28 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/02 11:57:48 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (NULL);
	while (lst)
	{
		if (!lst->next->next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

int	find_smallest(t_list **stack)
{
	int		small;
	t_list	*head;

	if ((*stack) == NULL || stack == NULL)
		return (0);
	head = *stack;
	small = head->value;
	while (head)
	{
		if (small > head->value)
			small = head->value;
		head = head->next;
	}
	return (small);
}

int	find_index(t_list **stack, int num)
{
	int		index;
	t_list	*head;

	if (stack == NULL || *stack == NULL)
		return (0);
	index = 1;
	head = *stack;
	while (head->value != num)
	{
		index++;
		head = head->next;
	}
	return (index);
}

void	ft_lstdelone(t_list *lst, void (del)(int *))
{
	if (!lst || !del)
		return ;
	if (&(lst->value) != NULL)
		del(&(lst->value));
}

void	ft_lstclear(t_list **lst, void (del)(int *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
