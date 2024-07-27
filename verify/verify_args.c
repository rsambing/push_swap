/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:23:36 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/25 08:13:08 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	liberar(int *numbers)
{
	free(numbers);
	exit(1);
}

int	check_numbers(int *numbers, int len)
{
	int	i;
	int	j;
	int	verif;

	i = -1;
	verif = 1;
	if (len == 1)
    	return (-1);
	while (++i < len - 1)
	{
		if (numbers[i] < numbers[i + 1])
			verif = 0;
		j = -1;
		while (++j < len)
		{
			if (numbers[i] == numbers[j] && i != j)
            	return (-1);
		}
	}
	if (verif != 0)
   		liberar(numbers);
	return (1);
}
