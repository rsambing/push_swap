/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar_mestre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:24:46 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 12:21:39 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static char	*deixar_3(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
	char	*temp;
    
    while (count_pilha(a) > 3)
    {
        t.cheapest = find_cheapest(a, b);
        t.target = find_target(t.cheapest, b);
		while (!(ft_i_pilha(a, t.cheapest) == 1 && ft_i_pilha(b, t.target) == 1))
		{
			if ((temp = NULL) || (ft_i_pilha(a, t.cheapest) <= (divi(count_pilha(a)) / 2) && ft_i_pilha(a, t.cheapest) != 1))
				temp = rotate_o(a);
			else if (ft_i_pilha(a, t.cheapest) != 1)
				temp = reverse_rotate_o(a);
			if (temp)
                saida = concatena_strings(saida, temp);
            if ((temp = NULL) || (ft_i_pilha(b, t.target) <= (divi(count_pilha(b)) / 2) && ft_i_pilha(b, t.target) != 1))
				temp = rotate_o(b);
			else if (ft_i_pilha(b, t.target) != 1)
				temp = reverse_rotate_o(b);
            if (temp)
		        saida = concatena_strings(saida, temp);
		}
			temp = push_o(b, a);
			saida = concatena_strings(saida, temp);	
    }
    ft_printf("***********************\n");
	return (saida);
}

static char *voltar_tudo(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
    char    *temp;
    while (count_pilha(a) > 0)
    {
        t.cheapest = find_cheapest2(a, b);
        t.target = find_target2(t.cheapest, b);
        while (!(ft_i_pilha(a, t.cheapest) == 1 && ft_i_pilha(b, t.target) == 1))
        {
            if ((temp = NULL) || (ft_i_pilha(a, t.cheapest) <= (divi(count_pilha(a)) / 2) && ft_i_pilha(a, t.cheapest) != 1))
                temp = rotate_o(a);
            else if (ft_i_pilha(a, t.cheapest) != 1)
                temp = reverse_rotate_o(a);
            if (temp)
                saida = concatena_strings(saida, temp);
            if ((temp = NULL) || (ft_i_pilha(b, t.target) <= (divi(count_pilha(b)) / 2) && ft_i_pilha(b, t.target) != 1))
                temp = rotate_o(b);
            else if (ft_i_pilha(b, t.target) != 1)
                temp = reverse_rotate_o(b);
            if (temp)
                saida = concatena_strings(saida, temp);
        }
            temp = push_o(b, a);
            saida = concatena_strings(saida, temp); 
    }
    return (saida);
}
static char *check_final(t_pilha *p)
{
    char    *temp;
    char    *saida;

    saida = NULL;
    while (check_pilha(p, count_pilha(p)) != 1)
    {
        temp = NULL;    
       if (ft_menor_i_pilha(p, count_pilha(p)) <= divi(count_pilha(p)) / 2)
            temp = rotate_o(p);
        else
            temp = reverse_rotate_o(p);
        saida = concatena_strings(saida, temp);
    }
    return (saida);
}

char *ordenar_mestre(t_pilha *a)
{
    t_pilha *b;
    t_targets t;
    char *saida;
    char *temp;
    int i;

    i = -1;
    saida = NULL;
    b = criar_pilha("b");
    if (!b)
        return (NULL);

    while (++i < 2)
    {
        temp = push_o(b, a);
        if (!temp)
        {
            b = apagar_pilha(b);
            return (NULL);
        }
        saida = concatena_strings(saida, temp);
        if (!saida)
        {
            b = apagar_pilha(b);
            return (NULL);
        }
    }

    t.cheapest = find_cheapest(a, b);
    t.target = find_target(t.cheapest, b);

    temp = deixar_3(a, b, NULL, t);
    if (temp)
    {
        saida = concatena_strings(saida, temp);
        if (!saida)
        {
            b = apagar_pilha(b);
            return (NULL);
        }
    }

    temp = ordenar_3(a, 3);
    if (temp)
    {
        saida = concatena_strings(saida, temp);
        if (!saida)
        {
            b = apagar_pilha(b);
            return (NULL);
        }
    }

    t.cheapest = find_cheapest2(b, a);
    t.target = find_target2(t.cheapest, a);

    temp = voltar_tudo(b, a, NULL, t);
    if (temp)
    {
        saida = concatena_strings(saida, temp);
        if (!saida)
        {
            b = apagar_pilha(b);
            return (NULL);
        }
    }

    temp = check_final(a);
    if (temp)
    {
        saida = concatena_strings(saida, temp);
        if (!saida)
        {
            b = apagar_pilha(b);
            return (NULL);
        }
    }

    b = apagar_pilha(b);
    return (saida);
}

