/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:04:06 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 14:11:49 by rsambing         ###   ########.fr       */
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
static void liberar_concat(char *saida, char *temp)
{
	free(saida);
    free(temp);
}

char	*concatena_strings(char *saida, char *temp)
{
    char *nova_saida;
    size_t tamanho_saida;
    size_t tamanho_temp;

    tamanho_saida = saida ? ft_strlen(saida) : 0;
    tamanho_temp = temp ? ft_strlen(temp) : 0;
    if (!saida)
    {
        nova_saida = ft_strdup(temp);
        if (!nova_saida)
            return (NULL);
        free(temp);
        return (nova_saida);
    }
    nova_saida = malloc(tamanho_saida + tamanho_temp + 1);
    if (nova_saida == NULL)
    {
        liberar_concat(saida, temp);
        return (NULL);
    }
    ft_strlcpy(nova_saida, saida, tamanho_saida + 1);
    ft_strlcat(nova_saida, temp, tamanho_saida + tamanho_temp + 1);
    liberar_concat(saida, temp);
    return (nova_saida);
}