#include "../libft/libft.h"
#include "../push_swap.h"

static char	*deixar_3(t_pilha *a, t_pilha *b, char *saida, int cheapest, int target)
{
	char	*temp;
    
    while (count_pilha(a) > 3)
    {
		while (!(ft_i_pilha(a, cheapest) == 1 && ft_i_pilha(b, target) == 1))
		{
            temp = NULL;
			if (ft_i_pilha(a, cheapest) <= (divi(count_pilha(a)) / 2) && ft_i_pilha(a, cheapest) != 1)
				temp = rotate_o(a);
			else if (ft_i_pilha(a, cheapest) != 1)
				temp = reverse_rotate_o(a);
			if (temp)
                saida = concatena_strings(saida, temp);
            if (ft_i_pilha(b, target) <= (divi(count_pilha(b)) / 2) && ft_i_pilha(b, target) != 1)
				temp = rotate_o(b);
			else if (ft_i_pilha(b, target) != 1)
				temp = reverse_rotate_o(b);
            if (temp)
		        saida = concatena_strings(saida, temp);
            cheapest = find_cheapest(a, b);
            target = find_target(cheapest, b);
		}
			temp = push_o(b, a);
			saida = concatena_strings(saida, temp);	
    }
	return (saida);
}


char    *ordenar_mestre(t_pilha *a)
{
    t_pilha *b;
    char    *saida;
    char    *temp;
    int i;

    i = -1;
    saida = NULL;
    b = criar_pilha("b");
    if (!b)
        return (NULL);
    while (++i < 2)
    {
        temp = push_o(b, a);
        saida = concatena_strings(saida, temp);
        if (!saida)
            return (NULL);
    }
    temp = deixar_3(a, b, NULL, find_cheapest(a, b), find_target(find_cheapest(a, b), b));
    saida = concatena_strings(saida, temp);
    temp = ordenar_3(a, 3);
    saida = concatena_strings(saida, temp);
    ft_printf("***************\n");
    imprimir_pilha(a);
    ft_printf("-------pilha a-------\n");
    imprimir_pilha(b);
    ft_printf("-------pilha b-------\n");
    b = apagar_pilha(b);
    return (saida);
}
