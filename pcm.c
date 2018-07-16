/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:58:18 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/15 20:58:23 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

t_root	*root_init(void)
{
	t_root	*newroot;

	newroot = (t_root *)ft_memalloc(sizeof(t_root));
	if (!newroot)
		return (NULL);
	newroot->r = newroot;
	newroot->l = newroot;
	newroot->d = newroot;
	newroot->u = newroot;
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
	newcolm->n = namespace;
	newcolm->r = root;
	newcolm->l = root->l;
	root->l->r = newcolm;
	root->l = newcolm;
	newcolm->u = newcolm;
	newcolm->d = newcolm;
	return (newcolm);
}

t_colo	*colo_init(char *name)
{
	t_colo	*newcolo;

	newcolo = (t_colo *)ft_memalloc(sizeof(t_colo));
	if (!newcolo)
		return (NULL);
	newcolo->n = name;
	newcolo->l = newcolo;
	newcolo->r = newcolo;
	newcolo->u = newcolo;
	newcolo->d = newcolo;
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
		newone->l = newone;
		newone->r = newone;
	}
	else
	{
		newone->l = rowleft;
		newone->r = rowleft->r;
		rowleft->r->l = newone;
		rowleft->r = newone;
	}
	newone->d = colhead;
	newone->u = colhead->u;
	colhead->u->d = newone;
	colhead->u = newone;
	colhead->s++;
	newone->c = colhead;
	return (newone);
}

t_colm	*ith(t_root *root, int i)
{
	int		j;
	t_colm	*ret;

	j = 0;
	ret = root->r;
	while (j < i)
	{
		ret = ret->r;
		j++;
	}
	return (ret);
}
