/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar_mestre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:24:46 by rsambing          #+#    #+#             */
/*   Updated: 2024/08/08 14:00:51 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static char	*deixar_3(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
	while (count_pilha(a) > 3 && !check_pilha(a, count_pilha(a)))
	{
		t.cheapest = find_cheapest(a, b);
		t.target = find_target(t.cheapest, b);
		while (!(first(a, t.cheapest) && first(b, t.target)))
		{
			t.temp = NULL;
			if ((torb(a, t.cheapest) && !first(a, t.cheapest)))
				t.temp = rotate_o(a);
			else if (!first(a, t.cheapest))
				t.temp = reverse_rotate_o(a);
			if (t.temp)
				saida = concatena_strings(saida, t.temp);
			t.temp = NULL;
			if ((torb(b, t.target) && !first(b, t.target)))
				t.temp = rotate_o(b);
			else if (!first(b, t.target))
				t.temp = reverse_rotate_o(b);
			if (t.temp)
				saida = concatena_strings(saida, t.temp);
		}
		t.temp = push_o(b, a);
		saida = concatena_strings(saida, t.temp);
	}
	return (saida);
}

static char	*voltar_tudo(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
	while (count_pilha(b) > 0)
	{
		t.target = find_target2(b->topo->valor, a);
		while (!first(a, t.target))
		{
			t.temp = NULL;
			if ((torb(a, t.target) && !first(a, t.target)))
				t.temp = rotate_o(a);
			else if (!first(a, t.cheapest))
				t.temp = reverse_rotate_o(a);
			if (t.temp)
				saida = concatena_strings(saida, t.temp);
		}
		t.temp = push_o(a, b);
		if (t.temp)
			saida = concatena_strings(saida, t.temp);
	}
	return (saida);
}

static char	*preparar_pilhas(t_pilha *a, t_pilha *b, char *saida)
{
	char	*temp;
	int		i;

	i = -1;
	while (++i < 2)
	{
		temp = push_o(b, a);
		saida = concatena_strings(saida, temp);
		if (!saida)
			return (NULL);
	}
	return (saida);
}

static char	*ordenar_final(t_pilha *a, t_pilha *b, char *saida)
{
	t_targets	t;
	char		*temp;

	t.target = 0;
	t.cheapest = 0;
	t.temp = NULL;
	temp = deixar_3(a, b, NULL, t);
	if (temp)
		saida = concatena_strings(saida, temp);
	temp = ordenar_3(a, 3);
	if (temp)
		saida = concatena_strings(saida, temp);
	temp = voltar_tudo(a, b, NULL, t);
	if (temp)
		saida = concatena_strings(saida, temp);
	temp = check_final(a);
	if (temp)
		saida = concatena_strings(saida, temp);
	return (saida);
}

char	*ordenar_mestre(t_pilha *a)
{
	t_pilha	*b;
	char	*saida;

	saida = NULL;
	b = criar_pilha("b ");
	if (!b)
		return (NULL);
	saida = preparar_pilhas(a, b, saida);
	if (!saida)
	{
		b = apagar_pilha(b);
		return (NULL);
	}
	saida = ordenar_final(a, b, saida);
	b = apagar_pilha(b);
	return (saida);
}
