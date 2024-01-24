/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:29:13 by muhakose          #+#    #+#             */
/*   Updated: 2023/10/14 12:59:11 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && *(c1 + i) == *(c2 + i) && s1[i] != 0)
		i++;
	if (i == n)
		return (0);
	return (*(c1 + i) - *(c2 + i));
}
/* int main()
{
	int c;

	c = strncmp("", "", 2);
	printf("%d\n",c);
	c = ft_strncmp("", "", 2);
	printf("%d",c);

	return 0;
} */