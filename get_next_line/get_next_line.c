/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:13:21 by zekaya            #+#    #+#             */
/*   Updated: 2023/02/18 16:08:10 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../Libft/libft.h"

char	*ft_get_read(int fd, char *str)
{
	int		count;
	char	*now_str;

	now_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!now_str)
		return (0);
	count = 1;
	while (! ft_strchr(str, '\n') && count != 0)
	{
		count = read(fd, now_str, BUFFER_SIZE);
		if (count == -1)
		{
			free (now_str);
			return (0);
		}
		now_str[count] = '\0';
		str = ft_strjoin(str, now_str);
	}
	free(now_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	str = ft_get_read(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_get_new_str(str);
	return (line);
}
