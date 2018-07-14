int		pugilist(t_root *root, t_colo **box, int sqr, int k)
{
	static t_one	*solution[27];
	t_colm			*colhead;
	size_t		num_ones;
	t_colm			*to_remove;
	t_one			*a_rowish;
	int				flag;

	if (root->R->N == NULL)
	{
		print_solution(solution, k, sqr);
		return (0);
	}
	colhead = root->R;
	to_remove = colhead;
	num_ones = colhead->S;
	while (colhead->N != NULL)
	{
		if (colhead->S < num_ones)
		{
			to_remove = colhead;
			num_ones = colhead->S;
		}
		colhead = colhead->R;
	}
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
