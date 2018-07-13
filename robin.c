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

t_colo  *colo_initializer(char *name)
{
    return ((t_colo *)ft_memalloc(sizeof(t_colo)));
}

t_one   *one_initializer(t_entry *colhead, t_one *rowleft)
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

t_colm  *ith(t_root *root, int i)
{
    int j;
    t_colm *ret;

    j = 0;
    ret = root->R;
    while (j < i)
    {
        ret = ret->R;
        j++;
    }
    return (ret);
}

char    **pugilist(t_root *root, t_colo *box, int sqr)
{
    return (NULL);
}

char    **programmer(t_piece *tetrimini, int sqr, t_root *root, t_colo *box)
{
    int     i;
    int     j;
    int     k;
    t_one   *last_one;

    i = 0;
    while (!(death(tetrimini[i], g_piece[END])))
    {
        j = 0;
        if (sqr - tetrimini[i].x - 1 <= 0 || sqr - tetrimini[i].y - 1 <= 0)
            return (NULL);
        while (j <= sqr - tetrimini[i].height)
        {
            k = 0;
            while (k <= sqr - tetrimini[i].width)
            {
                last_one = one_initializer(ith(root, i), NULL);
                last_one = one_initializer(box[sqr * (j + tetrimini[i].b[0].y) + k + tetrimini[i].b[0].y], last_one);
                last_one = one_initializer(box[sqr * (j + tetrimini[i].b[1].y) + k + tetrimini[i].b[1].y], last_one);
                last_one = one_initializer(box[sqr * (j + tetrimini[i].b[2].y) + k + tetrimini[i].b[2].y], last_one);
                last_one = one_initializer(box[sqr * (j + tetrimini[i].b[3].y) + k + tetrimini[i].b[3].y], last_one);
                k++;
            }
            j++;
        }
    }
    return (pugilist(root, box, sqr));
}

char    **wildcard(t_piece *tetrimini, int sqr)
{
    t_root  *root;
    t_colo  *box;
    int     i;

    box = (t_colo *)ft_memalloc(sqr * sqr * sizeof(t_colo));
    if (box == NULL)
        return (NULL);
    root = root_initializer();
    i = 0;
    while (!(death(tetrimini[i], g_piece[END])))
        colm_initializer(root, &('A' + i++));
    i = 0;
    while (i < sqr * sqr)
        box[i] = colo_initializer(ft_itoa(i));
    i = 0;
    return (programmer(tetrimini, sqr, root, box));
}

int     dot_sum(char *square, int side)
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
    int     maxim;
    
    nump = 0;
    while (!(death(tetrimini[nump], g_piece[END])))
        nump++;
    sqr = 2;
    while (sqr * sqr < 4 * nump)
        sqr++;
    while (!(candidates = wildcard(tetrimini, sqr)))
        sqr++;
    maxim = -1;
    while (*candidates)
    {
        if (dot_sum(*candidates, sqr) > maxim)
        {
            maxim = dot_sum(*candidates, sqr);
            output = *candidates;
        }
        candidates++;
    }
    return (output);
}
