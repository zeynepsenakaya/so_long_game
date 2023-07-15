/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by zekaya            #+#    #+#             */
/*   Updated: 2022/11/26 17:18:42 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i = 1;
	while (c)
	{
		i++;
		c = c / 10;
		if (c == 0)
			break ;
	}
	return (i);
}

static char	*tointeger(int n, int strlen, int number, char *str)
{
	while (strlen >= 0)
	{
		number = n % 10;
		str[strlen--] = number + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		strlen;
	char	*str;
	int		number;
	int		sign;

	strlen = intlen(n);
	number = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * strlen + 1);
	if (!str)
		return (0);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[strlen--] = '\0';
	tointeger(n, strlen, number, str);
	if (sign == -1 && str[0] == '0')
		str[0] = '-';
	return (str);
}
