/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:27:04 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 14:18:40 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

char	*ordenar_3(t_pilha *p, int len)
{
	char	*saida;
	char	*nova_saida;
	char	*temp;

	saida = NULL;
	if (ft_maior_i_pilha(p, len) == 1)
		saida = rotate_o(p);
	else if (ft_maior_i_pilha(p, len) == 2)
	{
		saida = reverse_rotate_o(p);
	}
	if (ft_menor_i_pilha(p, len) != 1)
	{
		if (!saida)
			return (swap_o(p));
		nova_saida = ft_strdup(saida);
		free(saida);
		temp = swap_o(p);
		saida = ft_strjoin(nova_saida, temp);
		free(temp);
		free(nova_saida);
	}
	return (saida);
}

static char	*deixar_3(t_pilha *a, t_pilha *b, int len)
{
	char	*saida;
	char	*temp;

	(void)len;
	saida = NULL;
	temp = NULL;
	while (count_pilha(a) != 3)
	{
		while (ft_menor_i_pilha(a, count_pilha(a)) != 1 && check_pilha(a,
				count_pilha(a)) == 0)
		{
			if (ft_menor_i_pilha(a, count_pilha(a)) <= divi(count_pilha(a)) / 2)
				temp = rotate_o(a);
			else
				temp = reverse_rotate_o(a);
			saida = concatena_strings(saida, temp);
		}
		if (check_pilha(a, count_pilha(a)) != 1)
		{
			temp = push_o(b, a);
			saida = concatena_strings(saida, temp);
		}
	}
	return (saida);
}

char	*ordenar_n(t_pilha *a, int len)
{
	char	*saida;
	char	*nova_saida;
	char	*temp;
	t_pilha	*b;

	(void)*nova_saida;
	(void)*temp;
	b = criar_pilha("b");
	if (!b)
		return (NULL);
	saida = deixar_3(a, b, len);
	if (!saida)
	{
		b = apagar_pilha(b);
		return (NULL);
	}
	temp = ordenar_3(a, 3);
	saida = concatena_strings(saida, temp);
	while (count_pilha(b) > 0)
	{
		temp = push_o(a, b);
		saida = concatena_strings(saida, temp);
	}
	b = apagar_pilha(b);
	return (saida);
}
