/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:31:02 by arissane          #+#    #+#             */
/*   Updated: 2024/04/16 10:33:15 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if a character is a digit. Takes in an int in order to
 * accommodate the full range of ASCII values.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
