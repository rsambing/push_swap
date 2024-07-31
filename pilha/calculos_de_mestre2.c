/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculos_de_mestre2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:01:48 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 10:06:01 by rsambing         ###   ########.fr       */
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
        if (aux->valor > n)
           return (1);
        aux = aux->ant;
    }
    return (-2);
}
int find_target2(int n, t_pilha *b)
{
    t_lista *aux;
    int mm;

    if (!b || !b->topo)
        return (-1);
    if (existe_mm(n, b) == -1)
        return (-1);
    else if (existe_mm(n, b) == -2)
        return (ft_menor_n_pilha(b, count_pilha(b)));
    aux = b->topo;
    while(aux != NULL)
    {
        if (aux->valor > n)
            mm = aux->valor;
        aux = aux->ant;
    }
    aux = b->topo;
    while (aux != NULL)
    {
        if (aux->valor < mm && aux->valor > n)
            mm = aux->valor;
        aux = aux->ant;
    }
    return (mm);
}
