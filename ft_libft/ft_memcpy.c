/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:17:33 by muhakose          #+#    #+#             */
/*   Updated: 2023/10/14 14:58:29 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	if (!dst && !src)
		return (0);
	i = 0;
	ptrdst = (unsigned char *)dst;
	ptrsrc = (const unsigned char *)src;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}

/* int main() {
    // Test data
    char source[] = "Hello, World!";
    char destination[20];
    char standard_memcpy_destination[20];

    // Use ft_memcpy to copy the data
    ft_memcpy(destination, source, strlen(source) + 1);
	printf("%s",destination);

    // Use the standard memcpy to copy the same data
    memcpy(standard_memcpy_destination, source, strlen(source) + 1);
	printf("%s",standard_memcpy_destination);

    if (strcmp(destination, standard_memcpy_destination) == 0) {
        printf("ft_memcpy and memcpy 
		produced the same result: %s\n", destination);
    } else {
        printf("ft_memcpy and memcpy produced different results.\n");
    }

    return 0;
} */