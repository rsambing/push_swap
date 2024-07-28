#include "../libft/libft.h"
#include "../push_swap.h"

static int existe_mm(int n, t_pilha *b)
{
    t_lista *aux;

    if (!b || !b->topo)
        return (-1);
    aux = b->topo;
    while (aux != NULL)
    {
        if (aux->valor < n)
           return (1);
        aux = aux->ant;
    }
    return (-2);
}
int find_target(int n, t_pilha *b)
{
    t_lista *aux;
    int mm;

    if (!b || !b->topo)
        return (-1);
    if (existe_mm(n, b) == -1)
        return (-1);
    else if (existe_mm(n, b) == -2)
        return (ft_maior_n_pilha(b, count_pilha(b)));
    aux = b->topo;
    while(aux != NULL)
    {
        if (aux->valor < n)
            mm = aux->valor;
        aux = aux->ant;
    }
    aux = b->topo;
    while (aux != NULL)
    {
        if (aux->valor > mm && aux->valor < n)
            mm = aux->valor;
        aux = aux->ant;
    }
    return (mm);
}

static int  calcular_dis_topo(int n, t_pilha *p)
{
    if (!p || !p->topo)
        return (-1);
    if (ft_i_pilha(p, n) == 1)
        return (0);
    if (ft_i_pilha(p, n) <= divi(count_pilha(p)) / 2)
		return (ft_i_pilha(p, n) - 1);
	else
		return (count_pilha(p) - ft_i_pilha(p, n) + 1);
}

int find_cheapest(t_pilha *a, t_pilha *b)
{
    int custo;
    int target;
    int cheapest;
    int min;
    t_lista *aux_a;
    
    if (!a || !b)
        return (-1);
    aux_a = a->topo;
    target = find_target(aux_a->valor,b);
    min = calcular_dis_topo(aux_a->valor, a) + calcular_dis_topo(target, b);
    cheapest = aux_a->valor;
    while (aux_a != NULL)
    {
        target = find_target(aux_a->valor,b);
        custo = calcular_dis_topo(aux_a->valor, a) + calcular_dis_topo(target, b);
        if (custo <= min)
            cheapest = aux_a->valor;
        aux_a = aux_a->ant;
    }
    return (cheapest);
}
