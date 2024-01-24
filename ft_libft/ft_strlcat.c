/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:49:43 by muhakose          #+#    #+#             */
/*   Updated: 2023/10/14 12:58:53 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen <= dstsize)
		srclen += dstlen;
	else
		srclen += dstsize;
	while (src[i] && dstlen + 1 < dstsize)
	{
		dst[dstlen++] = src[i++];
	}
	dst[dstlen] = '\0';
	return (srclen);
}

/* int main() {
    char destination[14] = "a";
    const char *source = "lorem ipsum dolar sit amet";
    size_t dstsize = sizeof(destination);

    // Test 1: Concatenate "World!" onto "Hello, "
    size_t result1 = ft_strlcat(destination, source, dstsize);
    printf("Result 1: %zu\n", result1);
    printf("Concatenated string: %s\n\n", destination);

    // Test 2: Concatenate "This is a very long string" onto "Short"
    char destination2[10] = "Short";
    const char *source2 = "This is a very long string";
    size_t dstsize2 = sizeof(destination2);
    size_t result2 = ft_strlcat(destination2, source2, dstsize2);
    printf("Result 2: %zu\n", result2);
    printf("Concatenated string: %s\n\n", destination2);

    // Test 3: Attempt to concatenate when there's not enough space
    char destination3[5] = "1234";
    const char *source3 = "567890";
    size_t dstsize3 = sizeof(destination3);
    size_t result3 = ft_strlcat(destination3, source3, dstsize3);
    printf("Result 3: %zu\n", result3);
    printf("Concatenated string: %s\n\n", destination3);

    return 0;
} */
