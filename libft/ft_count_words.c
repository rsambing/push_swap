/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:44:45 by rsambing          #+#    #+#             */
/*   Updated: 2024/06/29 11:44:47 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s)
{
	int		i;
	int		count;
	char	*str;

	str = ft_strtrim(s, " ");
	i = -1;
	count = 0;
	while (str[++i])
	{
		if ((str[i] >= 33 && str[i] <= 126) && (str[i + 1] == 32 || (str[i
						+ 1] >= 9 && str[i + 1] <= 13) || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}
