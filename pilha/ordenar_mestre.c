#include "../libft/libft.h"
#include "../push_swap.h"

static char	*deixar_3(t_pilha *a, t_pilha *b)
{
	char	*saida;
	char	*temp;

	saida = NULL;
	temp = NULL;
	while (count_pilha(a) != 3 && check_pilha(a, count_pilha(a)) != 1)
	{
		while (ft_i_pilha(a, find_cheapest(a, b)) != 1 && ft_i_pilha(b, find_target(find_cheapest(a, b), b)) != 1)
		{
			if (ft_i_pilha(a, find_cheapest(a, b)) != 1 && (ft_i_pilha(a, find_cheapest(a, b)) <= divi(count_pilha(a)) / 2)  && check_pilha(a, count_pilha(a)) != 1)
				temp = rotate_o(a);
			else if (ft_i_pilha(a, find_cheapest(a, b)) != 1 && check_pilha(a, count_pilha(a)) != 1)
				temp = reverse_rotate_o(a);
			saida = concatena_strings(saida, temp);
            if (ft_i_pilha(b, find_target(find_cheapest(a, b), b)) != 1 && (ft_i_pilha(b, find_target(find_cheapest(a, b), b)) <= divi(count_pilha(a)) / 2))
				temp = rotate_o(b);
			else if (ft_i_pilha(b, find_target(find_cheapest(a, b), b)) != 1 && check_pilha(a, count_pilha(a)) != 1)
				temp = reverse_rotate_o(b);
			saida = concatena_strings(saida, temp);
		}
        if (check_pilha(a, count_pilha(a)) != 1)
		{
			temp = push_o(b, a);
			saida = concatena_strings(saida, temp);	
    	}
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
    temp = deixar_3(a, b);
    saida = concatena_strings(saida, temp);
    imprimir_pilha(a);
    ft_printf("--------------\n");
    imprimir_pilha(b);
    ft_printf("--------------\n");
    b = apagar_pilha(b);
    return (saida);
}
