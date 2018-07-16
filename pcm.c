
#include "phil.h"

t_root *root_init(void)
{
    t_root *newroot;

    newroot = (t_root *)ft_memalloc(sizeof(t_root));
    if (!newroot)
        return (NULL);
    newroot->R = newroot;
    newroot->L = newroot;
    newroot->D = newroot;
    newroot->U = newroot;
    return (newroot);
}

t_colm *colm_init(t_root *root, char *name)
{
    t_colm *newcolm;
    char *namespace;

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

t_colo *colo_init(char *name)
{
    t_colo *newcolo;

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

t_one *one_init(t_entry *colhead, t_one *rowleft)
{
    t_one *newone;

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

t_colm *ith(t_root *root, int i)
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
