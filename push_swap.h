/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <rsambing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:49:05 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/29 13:03:26 by rsambing         ###   ########.fr       */
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

typedef struct targets
{
	int	cheapest;
	int	target;
} t_targets;
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
int					find_target(int n, t_pilha *b);
int					ft_menor_n_pilha(t_pilha *p, int len);
int					ft_maior_n_pilha(t_pilha *p, int len);
int					find_cheapest(t_pilha *a, t_pilha *b);
int					only_one_number(const char *str);
int					find_target2(int n, t_pilha *b);
int					find_cheapest2(t_pilha *a, t_pilha *b);
int					torb(t_pilha *a, int value);
int					is_first(t_pilha *p, int value);
int 				cal_custo(t_pilha *a, t_pilha *b, int v1, int v2);
int					MAIOR(int n1, int n2);
int					dis_topo(int n, t_pilha *p);

char				*swap_o(t_pilha *p);
char				*push_o(t_pilha *a, t_pilha *b);
char				*rotate_o(t_pilha *p);
char				*reverse_rotate_o(t_pilha *p);
char				*ordenar(t_pilha *p, int len);
char				*ordenar_3(t_pilha *p, int len);
char				*ordenar_n(t_pilha *a, int len);
char				*concatena_strings(char *saida, char *temp);
char    			*ordenar_mestre(t_pilha *a);
char				*check_final(t_pilha *p);

void				free_all_s(char **strings);

t_pilha				*criar_pilha(char *c);
t_pilha				*apagar_pilha(t_pilha *p);

#endif
