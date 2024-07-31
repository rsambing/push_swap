/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:53:29 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 09:40:16 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static long int	ft_atoi_besta(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	verify2args(char *str)
{
	int		i;
	char	c;
	char	ac;
	char	dc;

	i = 0;
	if ((ft_atoi_besta(str) < INT_MIN) || (ft_atoi_besta(str) > INT_MAX))
		return (-1);
	if (only_one_number(str))
		exit(1);
	while (str[i])
	{
		ac = str[i - 1];
		c = str[i];
		dc = str[i + 1];
		if (!(ft_isdigit(c) || ((c == '-' || c == '+') && ft_isdigit(dc)
					&& (!(ac) || ft_is_valid_space(str, i - 1)))
				|| ft_is_valid_space(str, i)))
			return (-1);
		i++;
	}
	return (1);
}

static int	verify2argss(char *str)
{
	int		i;
	char	c;
	char	ac;
	char	dc;

	i = 0;
	if ((ft_atoi_besta(str) < INT_MIN) || (ft_atoi_besta(str) > INT_MAX))
		return (-1);
	while (str[i])
	{
		ac = str[i - 1];
		c = str[i];
		dc = str[i + 1];
		if (c == ' ')
			return (-1);
		if (!(ft_isdigit(c) || ((c == '-' || c == '+') && ft_isdigit(dc)
					&& (!(ac) || ft_is_valid_space(str, i - 1)))
				|| ft_is_valid_space(str, i)))
			return (-1);
		i++;
	}
	return (1);
}

static int	verify_plus_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (verify2argss(av[i]) == -1)
			return (-1);
	}
	return (1);
}

int	verify_input(int ac, char **av)
{
	if (ac <= 1)
		exit(1);
	else if (ac == 2)
	{
		if (verify2args(av[1]) == -1)
			return (-1);
		return (2);
	}
	else
	{
		if (verify_plus_args(ac, av) == -1)
			return (-1);
		return (3);
	}
	return (1);
}
