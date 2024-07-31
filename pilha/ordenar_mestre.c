/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar_mestre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:24:46 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:05 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static char	*deixar_3(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
	char	*temp;

    while (count_pilha(a) > 3 && !check_pilha(a, count_pilha(a)))
    {
        t.cheapest = find_cheapest(a, b);
        t.target = find_target(t.cheapest, b);
		while (!(is_first(a, t.cheapest) && is_first(b, t.target)))
		{
			if ((temp = NULL) || (torb(a, t.cheapest) && !is_first(a, t.cheapest)))
				temp = rotate_o(a);
			else if (!is_first(a, t.cheapest))
				temp = reverse_rotate_o(a);
			if (temp)
                saida = concatena_strings(saida, temp);
            if ((temp = NULL) || (torb(b, t.target) && !is_first(b, t.target)))
				temp = rotate_o(b);
			else if (!is_first(b, t.target))
				temp = reverse_rotate_o(b);
            if (temp)
		        saida = concatena_strings(saida, temp);
		}
			temp = push_o(b, a);
			saida = concatena_strings(saida, temp);	
    }
	return (saida);
}

static char *voltar_tudo(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
    char    *temp;

    while (count_pilha(b) > 0)
    {
        t.target = find_target2(b->topo->valor, a);
        while (!is_first(a, t.target))
        {
            if ((temp = NULL) || (torb(a, t.target) && !is_first(a, t.target)))
				temp = rotate_o(a);
			else if (!is_first(a, t.cheapest))
				temp = reverse_rotate_o(a);
            if (temp)
		        saida = concatena_strings(saida, temp);
        }
        temp = push_o(a, b);
        if (temp)
            saida = concatena_strings(saida, temp); 
    }
    return (saida);
}

static char *preparar_pilhas(t_pilha *a, t_pilha *b, char *saida)
{
    char *temp;
    int i;

    i = -1;
    while (++i < 2)
    {
        temp = push_o(b, a);
        saida = concatena_strings(saida, temp);
        if (!saida)
            return (NULL);
    }
    return saida;
}

static char *ordenar_final(t_pilha *a, t_pilha *b, char *saida)
{
    t_targets t;
    char *temp;

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
    return saida;
}

char *ordenar_mestre(t_pilha *a)
{
    t_pilha *b;
    char *saida;

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
    imprimir_pilha(b);
    b = apagar_pilha(b);
    return (saida);
}
