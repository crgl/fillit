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

int		pugilist(t_root *root, t_colo **box, int sqr, int k)
{
	static t_one	*solution[27];
	t_colm			*to_remove;
	t_one			*a_rowish;
	int				flag;

	to_remove = root->R;
	colver(to_remove);
	if (to_remove->N == NULL || to_remove->D->N != NULL)
	{
		(to_remove->N == NULL) ? print_solution(solution, k, sqr) : 0;
		callback(to_remove);
		return (to_remove->N == NULL) ? 0 : 1;
	}
	a_rowish = to_remove->D;
	while (a_rowish->N == NULL)
	{
		callverback(a_rowish, TRUE, &colver, solution + k);
		flag = pugilist(root, box, sqr, k + 1);
		callverback(a_rowish, FALSE, &callback, solution + k);
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
