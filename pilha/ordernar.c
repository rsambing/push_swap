/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordernar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:35 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 08:20:43 by rsambing         ###   ########.fr       */
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

int	ft_menor_i_pilha(t_pilha *p, int len)
{
	int		i;
	int		menor;
	int		menori;
	t_lista	*aux;

	if (!p)
		return (-1);
	aux = p->topo;
	menor = aux->valor;
	aux = aux->ant;
	i = 1;
	menori = i;
	while (++i <= len)
	{
		if (menor > aux->valor)
		{
			menori = i;
			menor = aux->valor;
		}
		aux = aux->ant;
	}
	return (menori);
}

int	ft_maior_i_pilha(t_pilha *p, int len)
{
	int		i;
	int		maior;
	int		maiori;
	t_lista	*aux;

	if (!p)
		return (-1);
	aux = p->topo;
	maior = aux->valor;
	aux = aux->ant;
	i = 1;
	maiori = i;
	while (++i <= len)
	{
		if (maior < aux->valor)
		{
			maiori = i;
			maior = aux->valor;
		}
		aux = aux->ant;
	}
	return (maiori);
}

int	ft_i_pilha(t_pilha *p, int n)
{
	int		i;
	t_lista	*aux;

	if (!p)
		return (-1);
	aux = p->topo;
	i = 0;
	while (aux != NULL)
	{
		++i;
		if (aux->valor == n)
			return (i);
		aux = aux->ant;
	}
	return (-1);
}

char	*ordernar(t_pilha *p, int len)
{
	char	*saida;
	char	*temp;

	saida = NULL;
	temp = NULL;
	if (len == 2)
	{
		temp = swap_o(p);
		if (temp)
		{
			saida = ft_strdup(temp);
			free(temp);
		}
	}
	else if (len == 3)
	{
		temp = ordernar_3(p, 3);
		if (temp)
		{
			saida = ft_strdup(temp);
			free(temp);
		}
	}
	return (saida);
}
