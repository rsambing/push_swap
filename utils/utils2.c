/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:04:06 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 09:39:09 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int	only_one_number(const char *str) {
    if (*str == '\0') {
        return 0;
    }
    while (*str) {
        if (!ft_isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

static void	liberar_concat(char *saida, char *temp)
{
	free(saida);
	free(temp);
}

static int	a(char *saida)
{
	if (saida)
		return (ft_strlen(saida));
	return (0);
}

static int	b( char *temp)
{
	if (temp)
		return (ft_strlen(temp));
	return (0);
}

char	*concatena_strings(char *saida, char *temp)
{
	char	*nova_saida;
	size_t	tamanho_saida;
	size_t	tamanho_temp;

	tamanho_saida = a(saida);
	tamanho_temp = b(temp);
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
