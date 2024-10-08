/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:26:56 by rsambing          #+#    #+#             */
/*   Updated: 2024/08/07 15:27:29 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

char	*check_final(t_pilha *p)
{
	char	*temp;
	char	*saida;

	saida = NULL;
	while (check_pilha(p, count_pilha(p)) != 1)
	{
		temp = NULL;
		if (ft_menor_i_pilha(p, count_pilha(p)) <= (divi(count_pilha(p)) / 2))
			temp = rotate_o(p);
		else
			temp = reverse_rotate_o(p);
		saida = concatena_strings(saida, temp);
	}
	return (saida);
}

int	maior(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	torb(t_pilha *p, int value)
{
	if (ft_i_pilha(p, value) <= (divi(count_pilha(p)) / 2))
		return (1);
	return (0);
}

int	first(t_pilha *p, int value)
{
	if (ft_i_pilha(p, value) == 1)
		return (1);
	return (0);
}

int	n(char **temp)
{
	temp = NULL;
	(void) temp;
	return (0);
}
