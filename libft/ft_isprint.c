/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:48:17 by arissane          #+#    #+#             */
/*   Updated: 2024/04/16 10:52:15 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if a character is printable. Takes in an int in order to
 * accommodate the full range of ASCII values.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
