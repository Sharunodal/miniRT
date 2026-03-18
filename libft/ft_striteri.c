/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:14:43 by arissane          #+#    #+#             */
/*   Updated: 2024/04/25 11:07:58 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Apply a function to each character of a string, passing the index as
 * first argument.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	a;

	a = 0;
	while (s[a] != 0)
	{
		f(a, &s[a]);
		a++;
	}
}
