/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:48:58 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/13 09:49:01 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	*antes_da_pilha(int ac, char **av, int *len)
{
	int	*numbers;

	numbers = give_me_the_numbers(ac, av, len);
	if (!numbers || check_numbers(numbers, *len) == -1)
	{
		free(numbers);
		ft_printf("\033[1;31mError\n\033[0m");
		exit(1);
	}
	return (numbers);
}

int	main(int ac, char **av)
{
	char	*saida;
	int		*numbers;
	int		len;
	int		i;
	t_pilha	*a;

	i = -1;
	numbers = antes_da_pilha(ac, av, &len);
	a = criar_pilha("a");
	if (!a)
	{
		free(numbers);
		return (0);
	}
	while (++i < len)
		push(a, numbers[i]);
	ft_printf("");
	saida = ordernar(a, len);
	a = apagar_pilha(a);
	if (saida)
		free(saida);
	free(numbers);
	return (0);
}
