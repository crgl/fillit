/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxing_gloves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:57:21 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/15 20:57:25 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	print_solution(t_one **solution, int k, int sqr)
{
	int		i;
	char	str[sqr * (sqr + 1) + 1];
	char	name;
	int		loc;

	ft_memset(str, '.', sqr * (sqr + 1));
	str[sqr * (sqr + 1)] = '\0';
	i = -1;
	while (++i < k)
	{
		name = solution[i]->c->n[0];
		solution[i] = solution[i]->r;
		while (solution[i]->c->n[0] != name)
		{
			loc = ft_atoi(solution[i]->c->n);
			str[loc + loc / sqr] = name;
			solution[i] = solution[i]->r;
		}
	}
	i = -1;
	while (++i < sqr)
		str[(sqr + 1) * (i + 1) - 1] = '\n';
	ft_putstr(str);
}

void	colver(t_entry *col)
{
	char	*s;

	if (col->n == NULL)
		return ;
	s = col->n;
	col->l->r = col->r;
	col->r->l = col->l;
	col = col->d;
	while (col->n == NULL)
	{
		col = col->r;
		while (ft_strcmp(col->c->n, s))
		{
			col->d->u = col->u;
			col->u->d = col->d;
			col->c->s -= 1;
			col = col->r;
		}
		col = col->d;
	}
}

void	callback(t_entry *col)
{
	char	*s;

	if (col->n == NULL)
		return ;
	s = col->n;
	col = col->u;
	while (col->n == NULL)
	{
		col = col->l;
		while (ft_strcmp(col->c->n, s))
		{
			col->c->s += 1;
			col->d->u = col;
			col->u->d = col;
			col = col->l;
		}
		col = col->u;
	}
	col->r->l = col;
	col->l->r = col;
}

void	cvb(t_entry *row, t_bool cover, void (*f)(t_entry *col), t_one **sk)
{
	if (cover)
	{
		*sk = row;
		row = row->r;
		while (row->c->n[0] != (*sk)->c->n[0])
		{
			f(row->c);
			row = row->r;
		}
	}
	else
	{
		row = row->l;
		while (row->c->n[0] != (*sk)->c->n[0])
		{
			f(row->c);
			row = row->l;
		}
	}
}
