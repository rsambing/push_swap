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

char *mover_p_topo(t_pilha *a, t_pilha *b, int v1, int v2)
{
    int au, ad, bu, bd;
    char *saida = NULL;
    char *temp;

    au = ft_i_pilha(a, v1) - 1;
    bu = ft_i_pilha(b, v2) - 1;
    ad = count_pilha(a) - ft_i_pilha(a, v1) + 1;
    bd = count_pilha(b) - ft_i_pilha(b, v2) + 1;

    while (ft_i_pilha(a, v1) != 1 || ft_i_pilha(b, v2) != 1)
    {
        if (ft_i_pilha(a, v1) != 1 && ft_i_pilha(b, v2) != 1)
        {
            if (au <= ad && bu <= bd)
            {
                temp = rotate_o(a);
                if (temp)
                    saida = concatena_strings(saida, temp);
                temp = rotate_o(b);
                if (temp)
                    saida = concatena_strings(saida, temp);
            }
            else if (au > ad && bu > bd)
            {
                temp = reverse_rotate_o(a);
                if (temp)
                    saida = concatena_strings(saida, temp);
                temp = reverse_rotate_o(b);
                if (temp)
                    saida = concatena_strings(saida, temp);
            }
            else
            {
                if (au <= ad)
                {
                    temp = rotate_o(a);
                    if (temp)
                        saida = concatena_strings(saida, temp);
                }
                else
                {
                    temp = reverse_rotate_o(a);
                    if (temp)
                        saida = concatena_strings(saida, temp);
                }

                if (bu <= bd)
                {
                    temp = rotate_o(b);
                    if (temp)
                        saida = concatena_strings(saida, temp);
                }
                else
                {
                    temp = reverse_rotate_o(b);
                    if (temp)
                        saida = concatena_strings(saida, temp);
                }
            }
        }
        else if (ft_i_pilha(a, v1) != 1)
        {
            if (au <= ad)
            {
                temp = rotate_o(a);
                if (temp)
                    saida = concatena_strings(saida, temp);
            }
            else
            {
                temp = reverse_rotate_o(a);
                if (temp)
                    saida = concatena_strings(saida, temp);
            }
        }
        else if (ft_i_pilha(b, v2) != 1)
        {
            if (bu <= bd)
            {
                temp = rotate_o(b);
                if (temp)
                    saida = concatena_strings(saida, temp);
            }
            else
            {
                temp = reverse_rotate_o(b);
                if (temp)
                    saida = concatena_strings(saida, temp);
            }
        }
    }
    return (saida);
}


static char	*deixar_3(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
	char	*temp;

    while (count_pilha(a) > 3 && !check_pilha(a, count_pilha(a)))
    {
        t.cheapest = find_cheapest(a, b);
        t.target = find_target(t.cheapest, b);
		while (!(ft_i_pilha(a, t.cheapest) == 1 && ft_i_pilha(b, t.target) == 1))
		{
			temp = mover_p_topo(a, b, t.cheapest, t.target);
		    saida = concatena_strings(saida, temp);
		}
			temp = push_o(b, a);
			saida = concatena_strings(saida, temp);	
            ft_printf("inserindo...cheapest:%d target:%d\n", t.cheapest, t.target);
            imprimir_pilha(a);
            printf("-------A-------\n");
            printf("-------B-------\n");
            imprimir_pilha(b);
            printf("********************\n");
    }
	return (saida);
}

static char *voltar_tudo(t_pilha *a, t_pilha *b, char *saida, t_targets t)
{
    char    *temp;
    while (count_pilha(b) > 0)
    {
        t.cheapest = find_cheapest2(b, a);
        t.target = find_target2(t.cheapest, a);
        while (!is_first(b, t.cheapest) && !is_first(a, t.target))
        {
            if ((temp = NULL) || (torb(b, t.cheapest) == 1 && !is_first(b, t.cheapest)))
				temp = rotate_o(b);
			else if (!is_first(b, t.cheapest))
				temp = reverse_rotate_o(b);
			if (temp)
                saida = concatena_strings(saida, temp);
            if ((temp = NULL) || (torb(a, t.target) == 1 && !is_first(a, t.target)))
				temp = rotate_o(a);
			else if (!is_first(a, t.target))
				temp = reverse_rotate_o(a);
            if (temp)
		        saida = concatena_strings(saida, temp);
        }
        temp = push_o(a, b);
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
    imprimir_pilha(b);
    temp = voltar_tudo(a, b, NULL, t);
    if (temp)
        saida = concatena_strings(saida, temp);
    exit(1);
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
    b = apagar_pilha(b);
    return (saida);
}

