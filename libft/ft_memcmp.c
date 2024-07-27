/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:32:20 by rsambing          #+#    #+#             */
/*   Updated: 2024/05/17 14:36:31 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	i = 0;
	while (n-- > 0)
	{
		if (*(p1 + i) == *(p2 + i))
			i++;
		else
			return (*(p1 + i) - *(p2 + i));
	}
	return (0);
}
