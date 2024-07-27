/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:55:00 by rsambing          #+#    #+#             */
/*   Updated: 2024/06/05 09:55:02 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_char(char c, int *tamanho)
{
	write(1, &c, 1);
	(*tamanho)++;
}

void	ft_string(char *str, int *tamanho)
{
	if (str == NULL)
		ft_string("(null)", tamanho);
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			(*tamanho)++;
		}
	}
}

void	ft_int(int num, int *tamanho)
{
	if (num == -2147483648)
	{
		ft_string("-2147483648", tamanho);
		return ;
	}
	if (num < 0)
	{
		ft_char('-', tamanho);
		num = -num;
	}
	if (num >= 10)
		ft_int(num / 10, tamanho);
	ft_char((num % 10) + '0', tamanho);
}

static void	ft_hex(unsigned long long num, int *tamanho)
{
	if (num >= 16)
		ft_hex((num / 16), tamanho);
	ft_char("0123456789abcdef"[num % 16], tamanho);
}

void	ft_pointer(void *pi, int *tamanho)
{
	if (pi == 0)
		ft_string("(nil)", tamanho);
	else
	{
		ft_string("0x", tamanho);
		ft_hex((unsigned long long)pi, tamanho);
	}
}
