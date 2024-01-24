/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:00:09 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/17 11:56:31 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_everyisdigit(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
	{
		i++;
		if (isdigit(c[i]) == FALSE)
			return (FALSE);
	}
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (FALSE);
		i++;
	}
	return (1);
}

int	check_numbers(int num, char **av)
{
	int		repeat;
	char	**tmpav;
	int		i;
	int		j;

	i = 1;
	j = 0;
	repeat = 0;
	while (av[i] != 0)
	{
		j = 0;
		tmpav = ft_split(av[i], ' ');
		while (tmpav[j] != 0)
		{
			if (num == ft_atoi(tmpav[j]))
				repeat++;
			if (repeat > 1)
				return (free_array(j + 1, tmpav), FALSE);
			j++;
		}
		i++;
		free_array(j, tmpav);
	}
	return (TRUE);
}

int	check_errors(char **av)
{
	char	**tmpav;
	int		i;
	int		j;
	long	sayi;

	i = 0;
	while (av[++i] != 0)
	{
		j = 0;
		tmpav = ft_split(av[i], ' ');
		while (tmpav[j] != FALSE)
		{
			sayi = ft_atoi(tmpav[j]);
			if (sayi > 2147483647 || sayi < -2147483648)
				return (free_array(j + 1, tmpav), FALSE);
			if (ft_everyisdigit(tmpav[j]) == 0)
				return (free_array(j + 1, tmpav), FALSE);
			if (check_numbers(sayi, av) == 0)
				return (free_array(j + 1, tmpav), FALSE);
			j++;
		}
		free_array(j, tmpav);
	}
	return (TRUE);
}

int	sorted_already(t_list **stack)
{
	t_list	*head;
	int		temp;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return (FALSE);
	while (head->next != NULL)
	{
		temp = head->value;
		if (temp > head->next->value)
			return (FALSE);
		head = head->next;
	}
	return (TRUE);
}

char	**free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
	return (NULL);
}
