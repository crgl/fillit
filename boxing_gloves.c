

#include "phil.h"

void print_solution(t_one **solution, int k, int sqr)
{
    int i;
    char str[sqr * (sqr + 1) + 1];
    char name;
    int loc;

    ft_memset(str, '.', sqr * (sqr + 1));
    str[sqr * (sqr + 1)] = '\0';
    i = -1;
    while (++i < k)
    {
        name = solution[i]->C->N[0];
        solution[i] = solution[i]->R;
        while (solution[i]->C->N[0] != name)
        {
            loc = ft_atoi(solution[i]->C->N);
            str[loc + loc / sqr] = name;
            solution[i] = solution[i]->R;
        }
    }
    i = -1;
    while (++i < sqr)
        str[(sqr + 1) * (i + 1) - 1] = '\n';
    ft_putstr(str);
}

void colver(t_entry *col)
{
    char *s;

    if (col->N == NULL)
        return ;
    s = col->N;
    col->L->R = col->R;
    col->R->L = col->L;
    col = col->D;
    while (col->N == NULL)
    {
        col = col->R;
        while (ft_strcmp(col->C->N, s))
        {
            col->D->U = col->U;
            col->U->D = col->D;
            col->C->S -= 1;
            col = col->R;
        }
        col = col->D;
    }
}

void callback(t_entry *col)
{
    char *s;

    if (col->N == NULL)
        return ;
    s = col->N;
    col = col->U;
    while (col->N == NULL)
    {
        col = col->L;
        while (ft_strcmp(col->C->N, s))
        {
            col->C->S += 1;
            col->D->U = col;
            col->U->D = col;
            col = col->L;
        }
        col = col->U;
    }
    col->R->L = col;
    col->L->R = col;
}

void callverback(t_entry *row_entry, t_bool cover, void (*f)(t_entry *col), t_one **solutionk)
{
    if (cover)
    {
        *solutionk = row_entry;
        row_entry = row_entry->R;
        while (row_entry->C->N[0] != (*solutionk)->C->N[0])
        {
            f(row_entry->C);
            row_entry = row_entry->R;
        }
    }
    else
    {
        row_entry = row_entry->L;
        while (row_entry->C->N[0] != (*solutionk)->C->N[0])
        {
            f(row_entry->C);
            row_entry = row_entry->L;
        }
    }
}
