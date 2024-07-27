/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:27:04 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 08:20:55 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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

char	*ordernar_3(t_pilha *p, int len)
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
