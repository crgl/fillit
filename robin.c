/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:35:53 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/12 16:35:56 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

t_root  *root_initializer(void)
{
    t_root  *newroot;

    newroot = (t_root *)ft_memalloc(sizeof(t_root));
    if (!newroot)
        return (NULL);
    newroot->R = newroot;
    newroot->L = newroot;
    return (newroot);
}

t_colm  *colm_initializer(t_root *root, char *name)
{
    t_colm  *newcolm;

    newcolm = (t_colm *)ft_memalloc(sizeof(t_colm));
    if (!newcolm)
        return (NULL);
    newcolm->R = root;
    newcolm->L = root->L;
    root->L->R = newcolm;
    root->L = newcolm;
    return (newcolm);
}

t_colo  *colo_initializer(t_root *root, char *name)
{
    return ((t_colo *)ft_memalloc(sizeof(t_colo)));
}

t_one   *one_initializer(t_entry *colhead, t_entry *rowleft)
{
    t_one   *newone;

    newone = (t_one *)ft_memalloc(sizeof(t_one));
    if (!newone)
        return (NULL);
    if (rowleft == NULL)
    {
        newone->L = newone;
        newone->R = newone;
    }
    else
    {
        newone->L = rowleft;
        newone->R = rowleft->R;
        rowleft->R->L = newone;
        rowleft->R = newone;
    }
    newone->D = colhead;
    newone->U = colhead->U;
    colhead->U->D = newone;
    colhead->U = newone;
    colhead->S++;
    return (newone);
}

char    **pugilists(t_piece *tetrimini, int sqr)
{
    return (NULL);
}

int     min_sum(char *square, int side)
{
    int i;
    int output;

    output = 0;
    i = 0;
    while (square[i] != '\0')
    {
        if (square[i] == '.')
            output += i / side + i % side;
        i++;
    }
    return (output);
}

char    *layer_of_eggs(t_piece *tetrimini)
{
    char    *output;
    char    **candidates;
    int     nump;
    int     sqr;
    int     minsum;
    
    nump = 0;
    while (!(death(tetrimini[nump], g_piece[END])))
        nump++;
    sqr = 2;
    while (sqr * sqr < 4 * nump)
        sqr++;
    while (!(candidates = pugilist(tetrimini, sqr)))
        sqr++;
    minsum = sqr * sqr * (sqr + 1);
    while (*candidates)
    {
        if (min_sum(*candidates, sqr) < minsum)
        {
            minsum = min_sum(*candidates, sqr);
            output = *candidates;
        }
        candidates++;
    }
    return (output);
}
