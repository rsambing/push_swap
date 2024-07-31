/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:48:58 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 13:07:40 by rsambing         ###   ########.fr       */
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

static int	rr(char **sf, int i)
{
	if (sf[i + 1] && ((ft_strncmp(sf[i], "ra", ft_strlen(sf[i])) == 0 
		&& ft_strncmp(sf[i + 1], "rb", ft_strlen(sf[i])) == 0) || 
			(ft_strncmp(sf[i], "rb", ft_strlen(sf[i])) == 0 && 
				ft_strncmp(sf[i + 1], "ra", ft_strlen(sf[i])) == 0)))
		return (1);
	return (0);
}

static int	rrr(char **sf, int i)
{
	if (sf[i + 1] && ((ft_strncmp(sf[i], "rra", ft_strlen(sf[i])) == 0 
		&& ft_strncmp(sf[i + 1], "rrb", ft_strlen(sf[i])) == 0) || 
			(ft_strncmp(sf[i], "rrb", ft_strlen(sf[i])) == 0 && 
				ft_strncmp(sf[i + 1], "rra", ft_strlen(sf[i])) == 0)))
		return (1);
	return (0);
}

static void	saida_final(t_pilha *a, char *saida)
{
	(void)a;
	char	**sf;
	int	i;

	i = -1;
	sf = ft_split(saida, ' ');
	while (sf[++i])
	{
		if (rr(sf, i))
		{	
			i++;
			ft_printf("rr\n");
		}
		else if (rrr(sf, i))
		{	
			i++;
			ft_printf("rrr\n");
		}
		else
			ft_printf("%s\n",sf[i]);
	}
	free_all_s(sf);
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
	a = criar_pilha("a ");
	if (!a)
	{
		free(numbers);
		return (0);
	}
	while (++i < len)
		push(a, numbers[i]);
	saida = ordenar(a, len);
	saida_final(a, saida);
	a = apagar_pilha(a);
	if (saida)
		free(saida);
	free(numbers);
	return (0);
}
