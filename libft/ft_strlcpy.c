/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:39:54 by rsambing          #+#    #+#             */
/*   Updated: 2024/05/17 14:29:37 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return ((size_t)ft_strlen(src));
	i = -1;
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return ((size_t)ft_strlen(src));
}
