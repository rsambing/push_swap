/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:04:06 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 14:58:12 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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

int	ft_menor_n_pilha(t_pilha *p, int len)
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
	(void)menori;
	return (menor);
}

int	ft_maior_n_pilha(t_pilha *p, int len)
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
	(void)maiori;
	return (maior);
}
