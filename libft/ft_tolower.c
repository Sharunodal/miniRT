/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:49:10 by arissane          #+#    #+#             */
/*   Updated: 2024/04/17 09:50:53 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Convert an uppercase letter to lowercase. Takes in an int in order to
 * accommodate the full range of ASCII values.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
