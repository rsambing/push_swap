/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilha_essentials.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:21:55 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/15 16:21:56 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

t_pilha	*criar_pilha(char *id)
{
	t_pilha	*p;

	p = (t_pilha *)malloc(sizeof(t_pilha));
	if (!p)
		return (NULL);
	p->topo = NULL;
	p->id = ft_strdup(id);
	if (!p)
	{
		free(p);
		return NULL;
	}
	return (p);
}

int	push(t_pilha *p, int n)
{
	t_lista	*new;

	if (!p)
		return (-1);
	new = (t_lista *)malloc(sizeof(t_lista));
	if (!new)
		return (-1);
	new->ant = p->topo;
	p->topo = new;
	new->valor = n;
	return (1);
}

int	pop(t_pilha **p)
{
	int		n;
	t_lista	*aux;

	if (!p || !*p || !(*p)->topo)
    	return -1;
	aux = (*p)->topo;
	(*p)->topo = aux->ant;
	n = aux->valor;
	free(aux);
	return (n);
}

int	imprimir_pilha(t_pilha *p)
{
	int		i;
	t_lista	*aux;

	i = -1;
	if (!p)
		return (i);
	if (!p->topo)
		return (i);
	aux = p->topo;
	while (aux)
	{
		ft_printf("%d\n", aux->valor);
		aux = aux->ant;
	}
	return (i + 1);
}

t_pilha	*apagar_pilha(t_pilha *p)
{
	while (p->topo)
		pop(&p);
	free(p->id);
	free(p);
	return (NULL);
}
