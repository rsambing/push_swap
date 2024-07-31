/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculos_de_mestre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:26:37 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 08:26:40 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static int existe_mm(int n, t_pilha *b)
{
    t_lista *aux;

    if (!b || !b->topo)
        return (-1);
    aux = b->topo;
    while (aux != NULL)
    {
        if (aux->valor < n)
           return (1);
        aux = aux->ant;
    }
    return (-2);
}
int find_target(int n, t_pilha *b)
{
    t_lista *aux;
    int mm;

    if (!b || !b->topo)
        return (-1);
    if (existe_mm(n, b) == -1)
        return (-1);
    else if (existe_mm(n, b) == -2)
        return (ft_maior_n_pilha(b, count_pilha(b)));
    aux = b->topo;
    while(aux != NULL)
    {
        if (aux->valor < n)
            mm = aux->valor;
        aux = aux->ant;
    }
    aux = b->topo;
    while (aux != NULL)
    {
        if (aux->valor > mm && aux->valor < n)
            mm = aux->valor;
        aux = aux->ant;
    }
    return (mm);
}

int  dis_topo(int n, t_pilha *p)
{
    if (ft_i_pilha(p, n) == 1)
        return (0);
    if (torb(p, n))
		return (ft_i_pilha(p, n) - 1);
	else
		return (count_pilha(p) - ft_i_pilha(p, n) + 1);
}

int find_cheapest(t_pilha *a, t_pilha *b)
{
    int custo;
    int min;
    t_targets t;
    t_lista *aux_a;
    
    if (!a || !b)
        return (-1);
    aux_a = a->topo;
    t.target = find_target(aux_a->valor,b);
    t.cheapest = aux_a->valor;
    min = dis_topo(t.cheapest, a) + dis_topo(t.target, b);
    while (aux_a != NULL)
    {
        t.target = find_target(aux_a->valor,b);
        custo = dis_topo(aux_a->valor, a) + dis_topo(t.target, b);
        if (custo < min)
            t.cheapest = aux_a->valor;
        aux_a = aux_a->ant;
    }
    
    return (t.cheapest);
}
