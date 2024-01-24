/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:52:16 by muhakose          #+#    #+#             */
/*   Updated: 2023/12/17 12:01:25 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_list **stack_a, char **av)
{
	t_list	*new;
	char	**tmpav;
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (av[i] != 0)
	{
		j = 0;
		tmpav = ft_split(av[i], ' ');
		while (tmpav[j] != 0)
		{
			new = ft_lstnew(ft_atoi(tmpav[j]));
			ft_lstadd_back(stack_a, new);
			j++;
		}
		i++;
		free_array(j, tmpav);
	}
}

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (check_errors(av) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, av);
	sort_list(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

//	system("leaks push_swap");
// 	atexit(&leaks);