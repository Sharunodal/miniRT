/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:28:00 by arissane          #+#    #+#             */
/*   Updated: 2025/01/27 11:01:20 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c2;
	void			*p;

	i = 0;
	str = (unsigned char *) s;
	c2 = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == c2)
		{
			return ((void *) &s[i]);
			return (p);
		}
		i++;
	}
	return (NULL);
}
