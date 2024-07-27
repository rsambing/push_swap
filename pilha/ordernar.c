/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordernar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:35 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 14:11:29 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

char	*ordenar(t_pilha *p, int len)
{
	char	*saida;

	saida = NULL;
	if (len == 2)
		saida = swap_o(p);
	else if (len == 3)
		saida = ordenar_3(p, 3);
	else if (len > 3 && len < 13)
		saida = ordenar_n(p, len);
	if (!saida)
		return (NULL);
	return (saida);
}
