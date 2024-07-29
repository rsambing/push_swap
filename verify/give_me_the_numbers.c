/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_the_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:23:23 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 13:03:09 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static int	count_elements(char **nums_string)
{
	int	len;

	len = 0;
	while (nums_string[len])
		len++;
	return (len);
}

void	free_all_s(char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
		free(strings[i]);
	free(strings);
}

static int	*get_nums(char *str, int *len)
{
	char	**nums_string;
	int		*nums;
	int		i;
	int		j;

	nums_string = ft_split(str, ' ');
	if (!nums_string)
		return (NULL);
	nums = (int *)malloc(sizeof(int) * count_elements(nums_string));
	if (!nums)
	{
		free_all_s(nums_string);
		return (NULL);
	}
	i = 0;
	j = count_elements(nums_string);
	(*len) = count_elements(nums_string);
	while (nums_string[i])
		nums[--j] = ft_atoi(nums_string[i++]);
	free_all_s(nums_string);
	return (nums);
}

static char	*verify_input_3(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (i < ac)
	{
		temp = ft_strjoin(str, av[i++]);
		free(str);
		if (!temp)
			return (NULL);
		str = ft_strjoin(temp, " ");
		free(temp);
		if (!str)
			return (NULL);
	}
	return (str);
}

int	*give_me_the_numbers(int ac, char **av, int *len)
{
	int		*nums;
	char	*str;

	if (verify_input(ac, av) == -1)
		return (NULL);
	else if (verify_input(ac, av) == 2)
	{
		nums = get_nums(av[1], len);
		if (!nums)
			return (NULL);
		return (nums);
	}
	else if (verify_input(ac, av) == 3)
	{
		str = verify_input_3(ac, av);
		if (!str)
			return (NULL);
		nums = get_nums(str, len);
		(*len)--;
		free(str);
		if (!nums)
			return (NULL);
		return (nums);
	}
	return (NULL);
}
