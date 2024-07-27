/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:34:22 by rsambing          #+#    #+#             */
/*   Updated: 2024/05/17 13:34:40 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	d = (char *)dest;
	s = (char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (++i < n)
			d[i] = s[i];
	}
	else
	{
		i = n + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	return (dest);
}
