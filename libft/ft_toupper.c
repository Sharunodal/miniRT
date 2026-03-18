/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:25:50 by arissane          #+#    #+#             */
/*   Updated: 2024/04/17 08:47:32 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Convert a lowercase letter to uppercase. Takes in an int in order to
 * accommodate the full range of ASCII values.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
