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

t_root	*root_init(void)
{
	t_root	*newroot;

	newroot = (t_root *)ft_memalloc(sizeof(t_root));
	if (!newroot)
		return (NULL);
	newroot->R = newroot;
	newroot->L = newroot;
	return (newroot);
}

t_colm	*colm_init(t_root *root, char *name)
{
	t_colm	*newcolm;
	char	*namespace;

	newcolm = (t_colm *)ft_memalloc(sizeof(t_colm));
	namespace = ft_strdup(name);
	if (!newcolm || !namespace)
		return (NULL);
	newcolm->N = namespace;
	newcolm->R = root;
	newcolm->L = root->L;
	root->L->R = newcolm;
	root->L = newcolm;
	newcolm->U = newcolm;
	newcolm->D = newcolm;
	return (newcolm);
}

t_colo	*colo_init(char *name)
{
	t_colo	*newcolo;

	newcolo = (t_colo *)ft_memalloc(sizeof(t_colo));
	if (!newcolo)
		return (NULL);
	newcolo->N = name;
	newcolo->L = newcolo;
	newcolo->R = newcolo;
	newcolo->U = newcolo;
	newcolo->D = newcolo;
	return (newcolo);
}

t_one	*one_init(t_entry *colhead, t_one *rowleft)
{
	t_one	*newone;

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
	newone->C = colhead;
	return (newone);
}

t_colm	*ith(t_root *root, int i)
{
	int		j;
	t_colm	*ret;

	j = 0;
	ret = root->R;
	while (j < i)
	{
		ret = ret->R;
		j++;
	}
	return (ret);
}

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
	return ;
}

void	colver(t_entry *col)
{
	char	*s;

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

void	callback(t_entry *col)
{
	char	*s;

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

int		pugilist(t_root *root, t_colo **box, int sqr, int k)
{
	static t_one	*solution[27];
	t_colm			*to_remove;
	t_one			*a_rowish;
	int				flag;

	if (root->R->N == NULL)
	{
		print_solution(solution, k, sqr);
		return (0);
	}
	to_remove = root->R;
	colver(to_remove);
	if (to_remove->D->N != NULL)
	{
		callback(to_remove);
		return (1);
	}
	a_rowish = to_remove->D;
	while (a_rowish->N == NULL)
	{
		solution[k] = a_rowish;
		a_rowish = a_rowish->R;
		while (a_rowish->C->N[0] != solution[k]->C->N[0])
		{
			colver(a_rowish->C);
			a_rowish = a_rowish->R;
		}
		flag = pugilist(root, box, sqr, k + 1);
		a_rowish = a_rowish->L;
		while (a_rowish->C->N[0] != solution[k]->C->N[0])
		{
			callback(a_rowish->C);
			a_rowish = a_rowish->L;
		}
		if (flag == 0)
			break ;
		a_rowish = a_rowish->D;
	}
	callback(to_remove);
	return (flag);
}

int		programmer(t_piece *tris, int sqr, t_root *root, t_colo **box)
{
	int		i;
	int		j;
	int		k;
	t_one	*l1;

	i = -1;
	while (!(death(tris + ++i, &g_piece[END])))
	{
		j = -1;
		if (sqr < tris[i].width || sqr < tris[i].height)
			return (1);
		while (++j <= sqr - tris[i].height)
		{
			k = -1;
			while (++k <= sqr - tris[i].width)
			{
				l1 = one_init(ith(root, i), NULL);
				l1 = one_init(box[sqr * (j + POS(0).y) + k + POS(0).x], l1);
				l1 = one_init(box[sqr * (j + POS(1).y) + k + POS(1).x], l1);
				l1 = one_init(box[sqr * (j + POS(2).y) + k + POS(2).x], l1);
				l1 = one_init(box[sqr * (j + POS(3).y) + k + POS(3).x], l1);
			}
		}
	}
	return (pugilist(root, box, sqr, 0));
}

int		wildcard(t_piece *tris, int sqr)
{
	t_root	*root;
	t_colo	**box;
	int		i;
	char	alpha[2];
	t_colm	*check;

	alpha[0] = 'A';
	alpha[1] = '\0';
	if ((box = (t_colo **)ft_memalloc(sqr * sqr * sizeof(t_colo*))) == NULL)
		return (-1);
	root = root_init();
	i = 0;
	while (!(death(tris + i++, &g_piece[END])))
	{
		if ((check = colm_init(root, alpha)) == NULL)
			return (-1);
		alpha[0] += 1;
	}
	i = -1;
	while (++i < sqr * sqr)
	{
		if ((box[i] = colo_init(ft_itoa(i))) == NULL)
			return (-1);
	}
	return (programmer(tris, sqr, root, box));
}

void	layer_of_eggs(t_piece *tris)
{
	int		nump;
	int		sqr;
	int		check;

	if (tris == NULL)
	{
		ft_putendl("error");
		ft_putendl_fd("UNACCEPTABLE", 2);
		return ;
	}
	nump = 0;
	while (!(death(tris + nump, &g_piece[END])))
		nump++;
	sqr = 2;
	while (sqr * sqr < 4 * nump)
		sqr++;
	while ((check = wildcard(tris, sqr)) > 0)
		sqr++;
	if (check < 0)
	{
		ft_putendl("error");
		ft_putendl_fd("There has been a mallocation error!", 2);
	}
}
