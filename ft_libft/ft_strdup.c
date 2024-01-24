/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:16:00 by muhakose          #+#    #+#             */
/*   Updated: 2023/10/14 15:08:09 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char *) malloc ((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

/* int main() {
    const char *original = "Hello, World!";
    char *duplicate = strdup(original);

    if (duplicate == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);

    // Don't forget to free the allocated memory when done.
    free(duplicate);

    return 0;
}
 */