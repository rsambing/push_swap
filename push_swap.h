/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:49:05 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/27 08:21:02 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct lista
{
	int				valor;
	struct lista	*ant;
}					t_lista;

typedef struct pilha
{
	t_lista			*topo;
	char			*id;
}					t_pilha;

int					verify_input(int ac, char **av);
int					*give_me_the_numbers(int ac, char **av, int *len);
int					check_numbers(int *numbers, int len);
int					push(t_pilha *p, int n);
int					pop(t_pilha **p);
int					imprimir_pilha(t_pilha *p);
int					check_pilha(t_pilha *p, int len);
int					ft_menor_i_pilha(t_pilha *p, int len);
int					ft_maior_i_pilha(t_pilha *p, int len);
int					ft_i_pilha(t_pilha *p, int n);
int					count_pilha(t_pilha *p);
int					divi(int n);

char				*swap_o(t_pilha *p);
char				*push_o(t_pilha *a, t_pilha *b);
char				*rotate_o(t_pilha *p);
char				*reverse_rotate_o(t_pilha *p);
char				*ordernar(t_pilha *p, int len);
char				*ordernar_3(t_pilha *p, int len);

t_pilha				*criar_pilha(char *c);
t_pilha				*apagar_pilha(t_pilha *p);

#endif
