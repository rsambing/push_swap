/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:01:12 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 13:29:59 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

char	*swap_o(t_pilha *p)
{
	int		temp;
	char	*op;
	char	*temp_op;
	t_lista	*aux;

	op = NULL;
	temp_op = NULL;
	if (!p || !p->topo || !p->topo->ant)
		return (NULL);
	op = ft_strdup("s");
	if (!op)
		return (NULL);
	temp_op = ft_strjoin(op, p->id);
	free(op);
	op = temp_op;
	if (!op)
		return (NULL);
	ft_printf("%s\n", op);
	aux = p->topo;
	temp = aux->valor;
	aux->valor = aux->ant->valor;
	aux->ant->valor = temp;
	return (op);
}

char	*push_o(t_pilha *a, t_pilha *b)
{
	char	*op;
	char	*temp_op;

	if (!a || !b || !b->topo)
		return (NULL);
	op = ft_strdup("p");
	if (!op)
		return (NULL);
	temp_op = ft_strjoin(op, a->id);
	free(op);
	op = temp_op;
	if (!op)
		return (NULL);
	ft_printf("%s\n", op);
	push(a, b->topo->valor);
	pop(&b);
	return (op);
}

char	*rotate_o(t_pilha *p)
{
	int		temp;
	char	*op;
	char	*temp_op;
	t_lista	*aux;

	if (!p || !p->topo)
		return (NULL);
	op = ft_strdup("r");
	if (!op)
		return (NULL);
	temp_op = ft_strjoin(op, p->id);
	free(op);
	op = temp_op;
	if (!op)
		return (NULL);
	ft_printf("%s\n", op);
	aux = p->topo;
	temp = aux->valor;
	while (aux->ant != NULL)
	{
		aux->valor = aux->ant->valor;
		aux = aux->ant;
	}
	aux->valor = temp;
	return (op);
}

char	*reverse_rotate_o(t_pilha *p)
{
	char	*op;
	char	*temp_op;
	t_lista	*aux;
	t_lista	*aux2;

	if (!p || !p->topo || !p->topo->ant)
		return (NULL);
	op = ft_strdup("rr");
	if (!op)
		return (NULL);
	temp_op = ft_strjoin(op, p->id);
	free(op);
	op = temp_op;
	if (!op)
		return (NULL);
	ft_printf("%s\n", op);
	aux = p->topo;
	while (aux->ant->ant != NULL)
		aux = aux->ant;
	aux2 = aux->ant;
	aux->ant = NULL;
	aux2->ant = p->topo;
	p->topo = aux2;
	return (op);
}

int	divi(int n)
{
	if (n % 2 == 0)
		return (n);
	return (n + 1);
}
