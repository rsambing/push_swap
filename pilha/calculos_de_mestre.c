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

int cal_custo(t_pilha *a, t_pilha *b, int v1, int v2)
{
    int au, ad, bu, bd;
    int custo1, custo2, custo3, custo4;

    // Índices das posições dos valores v1 e v2 nas pilhas a e b
    au = ft_i_pilha(a, v1) - 1;
    bu = ft_i_pilha(b, v2) - 1;
    ad = count_pilha(a) - ft_i_pilha(a, v1) + 1;
    bd = count_pilha(b) - ft_i_pilha(b, v2) + 1;

    // Caso 1: Mover ambos para cima simultaneamente
    custo1 = (au > bu) ? au : bu;

    // Caso 2: Mover ambos para baixo simultaneamente
    custo2 = (ad > bd) ? ad : bd;

    // Caso 3: Mover v1 para cima e v2 para baixo
    custo3 = au + bd;

    // Caso 4: Mover v1 para baixo e v2 para cima
    custo4 = ad + bu;

    // Retorna o menor custo entre os quatro casos
    int custo_min = custo1;
    if (custo2 < custo_min) custo_min = custo2;
    if (custo3 < custo_min) custo_min = custo3;
    if (custo4 < custo_min) custo_min = custo4;

    return custo_min;
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
    min = cal_custo(a, b, t.cheapest, t.target);
    while (aux_a != NULL)
    {
        t.target = find_target(aux_a->valor,b);
        custo = cal_custo(a, b, aux_a->valor, t.target);
        ft_printf("valor atual:%d\ntarget:%d\ncusto:%d\n.\n", aux_a->valor, t.target, custo);
        if (custo < min)
            t.cheapest = aux_a->valor;
        aux_a = aux_a->ant;
    }
    
    return (t.cheapest);
}
