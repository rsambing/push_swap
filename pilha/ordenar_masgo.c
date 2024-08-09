/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar_masgo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:39:01 by rsambing          #+#    #+#             */
/*   Updated: 2024/08/08 14:43:51 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static int	ft_vi_pilha(t_pilha *a, t_pilha *b, int n)
{
	int		i;
	t_lista	*aux;

	if (!a && !b)
		return (-1);
	aux = a->topo;
	i = 0;
	while (aux != NULL)
	{
		if (aux->valor < n)
			i++;
		aux = aux->ant;
	}
	if (!b)
		return (i + 1);
	aux = b->topo;
	while (aux != NULL)
	{
		if (aux->valor < n)
			i++;
		aux = aux->ant;
	}
	return (i + 1);
}

static int	ft_max_bits(t_pilha *a)
{
	int	max;
	int	max_bits;

	max_bits = 0;
	max = count_pilha(a);
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static char	*sort_by_bit(t_pilha *a, t_pilha *b, int bit, char *saida)
{
	int		n;
	int		i;
	int		value;
	char	*temp;

	n = count_pilha(a);
	i = -1;
	while (++i < n && !check_pilha(a, count_pilha(a)))
	{
		temp = NULL;
		value = ft_vi_pilha(a, b, a->topo->valor);
		if ((value >> bit) & 1)
		{
			temp = rotate_o(a);
			if (temp)
				saida = concatena_strings(saida, temp);
		}
		else
		{
			temp = push_o(b, a);
			if (temp)
				saida = concatena_strings(saida, temp);
		}
	}
	return (saida);
}

static char	*return_elements_to_a(t_pilha *a, t_pilha *b, char *saida)
{
	char	*temp;

	while (count_pilha(b) > 0)
	{
		temp = push_o(a, b);
		if (temp)
			saida = concatena_strings(saida, temp);
	}
	return (saida);
}

char	*radix_sort(t_pilha *a, t_pilha *b, char *saida)
{
	int		max_bits;
	int		bit;

	max_bits = ft_max_bits(a);
	bit = -1;
	while (++bit < max_bits)
	{
		saida = sort_by_bit(a, b, bit, saida);
		saida = return_elements_to_a(a, b, saida);
	}
	return (saida);
}
