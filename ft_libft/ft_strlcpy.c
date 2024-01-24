/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:19:49 by muhakose          #+#    #+#             */
/*   Updated: 2023/10/14 12:58:57 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= srclen)
		j = dstsize - 1;
	else
		j = srclen;
	while (i < j)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/* int main() {
    char dest[0];
    const char *source = "lorem ipsum";  
	int size = 10;

    // Test cases
    size_t result1 = ft_strlcpy(dest, source, sizeof(dest));
	write(1, "\n" , 1);
	write(1, "ft_strlcpy == ", 15);
	write(1, dest, 15);
	write(1, "\n" , 1);
    size_t result2 = strlcpy(dest, source, sizeof(dest));
	write(1, "\n" , 1);
	write(1, "strlcpy    == ", 15);
	write(1, dest, 15);
	write(1, "\n" , 1);

    // Display the results
	
	
    // printf("Result of ft_strlcpy: %zu\n", result1);
    // printf("Destination after ft_strlcpy: %s\n", dest);

    // printf("Result of strlcpy: %zu\n", result2);
    // printf("Destination after strlcpy: %s\n", dest); 

    return 0;
} */