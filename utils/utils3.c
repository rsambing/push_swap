#include "../libft/libft.h"
#include "../push_swap.h"

char	*check_final(t_pilha *p)
{
    char    *temp;
    char    *saida;

    saida = NULL;
    while (check_pilha(p, count_pilha(p)) != 1)
    {
        ft_printf("ola\n");
        temp = NULL;    
       if (ft_menor_i_pilha(p, count_pilha(p)) <= divi(count_pilha(p)) / 2)
            temp = rotate_o(p);
        else
            temp = reverse_rotate_o(p);
        saida = concatena_strings(saida, temp);
    }
    return (saida);
}

int maior(int n1, int n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}

int torb(t_pilha *p, int value)
{
    if (ft_i_pilha(p, value) <= (divi(count_pilha(p)) / 2))
        return (1);
    return (0);
}

int is_first(t_pilha *p, int value)
{
    if (ft_i_pilha(p, value) == 1)
        return (1);
    return (0);
}

int ft_abs(int n)
{
    if (n < 0)
        return (n * -1);
    return (n);
}


