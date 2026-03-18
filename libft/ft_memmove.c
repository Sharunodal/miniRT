/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:22:26 by arissane          #+#    #+#             */
/*   Updated: 2024/05/11 09:22:28 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Helper function to copy memory when regions do not overlap
 */
static void	copystr(char *dest, char *sorc, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		dest[a] = sorc[a];
		a++;
	}
}

/**
 * Copy a block of memory from source to destination, handling overlapping regions
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sorc;

	if ((!dst && !src) || dst == src)
		return (dst);
	dest = (char *)dst;
	sorc = (char *)src;
	if (dest > sorc)
	{
		while (len > 0)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
	}
	else
		copystr(dest, sorc, len);
	return (dst);
}
