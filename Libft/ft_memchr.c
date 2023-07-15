/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:03:57 by zekaya            #+#    #+#             */
/*   Updated: 2022/11/26 19:57:57 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
		n--;
	}
	if (c == '\0')
		return ((void *)s + i);
	return (NULL);
}
