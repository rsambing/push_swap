/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordernar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:35 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 12:38:24 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int	check_pilha(t_pilha *p, int len)
{
	int		i;
	t_lista	*aux;

	if (!p)
		return (0);
	aux = p->topo;
	i = -1;
	while (++i < len - 1)
	{
		if (aux->valor > aux->ant->valor)
			return (0);
		aux = aux->ant;
	}
	return (1);
}

int	count_pilha(t_pilha *p)
{
	int		i;
	t_lista	*aux;

	i = 0;
	aux = p->topo;
	while (aux != NULL)
	{
		i++;
		aux = aux->ant;
	}
	return (i);
}

char	*ordenar(t_pilha *p, int len)
{
	char	*saida;

	saida = NULL;
	if (len == 2)
		saida = swap_o(p);
	else if (len == 3)
		saida = ordenar_3(p, 3);
	else if (len > 3 && len < 6)
		saida = ordenar_n(p, len);
	else
		saida = ordenar_mestre(p);
	if (!saida)
		return (NULL);
	return (saida);
}
