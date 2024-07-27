/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:55:37 by rsambing          #+#    #+#             */
/*   Updated: 2024/06/05 09:55:39 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_unsigned(unsigned int num, int *tamanho)
{
	if (num >= 10)
		ft_unsigned(num / 10, tamanho);
	ft_char((num % 10) + '0', tamanho);
}

void	ft_hex_lower(unsigned int num, int *tamanho)
{
	if (num >= 16)
		ft_hex_lower((num / 16), tamanho);
	ft_char("0123456789abcdef"[num % 16], tamanho);
}

void	ft_hex_upper(unsigned int num, int *tamanho)
{
	if (num >= 16)
		ft_hex_upper((num / 16), tamanho);
	ft_char("0123456789ABCDEF"[num % 16], tamanho);
}
