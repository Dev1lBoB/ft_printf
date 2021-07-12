/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:53:41 by wpersimm          #+#    #+#             */
/*   Updated: 2020/10/31 09:38:50 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy1(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src == 0 && dst == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((char *)(dst + i)) = *((char *)(src + i));
		i++;
	}
	*((char *)(dst + i)) = 0;
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen(s1) * sizeof(const char) + 1);
	if (s2 == NULL)
		return (NULL);
	s2 = ft_memcpy1(s2, s1, ft_strlen(s1));
	return (s2);
}
