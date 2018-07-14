/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_mcgraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:22:47 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/14 14:23:09 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

t_piece	*parse_square(int fd, int *check)
{
	char	square[20];
	char	c[1];

	*check = read(fd, square, 20);
	if (*check == 20)
	{
		*check = read(fd, c, 1);
		if (*c == '\n' || check == 0)
		{
			return (parse_piece(square));
		}
		return (NULL);
	}
	else
		return (NULL);
}

t_bool	death(t_piece *p1, t_piece *p2)
{
	int	i;

	i = -1;
	if (p1->width == p2->width && p1->height == p2->height)
	{
		while (++i < 4)
			if (p1->b[i].x != p2->b[i].x || p1->b[i].y != p2->b[i].y)
				return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

t_piece	*filet(int fd, t_piece *input, int check, size_t i)
{
	t_piece	temp[27];
	t_piece	*output;

	while (!(death(input, &g_piece[END])))
	{
		if (i == 26)
			return (NULL);
		input = parse_square(fd, &check);
		if (input == NULL)
			return (NULL);
		temp[i++] = *input;
		if (check == 0)
			break ;
	}
	temp[i] = g_piece[END];
	if (i < 2)
		return (NULL);
	output = (t_piece *)malloc(((i + 1) * sizeof(t_piece)));
	output[i] = g_piece[END];
	while (i)
	{
		i--;
		output[i] = temp[i];
	}
	return (output);
}

void	fillit(int fd)
{
	t_piece	*tris;
	size_t	i;
	t_piece	*input;
	int		check;

	i = 0;
	input = &g_piece[I];
	check = 20;
	tris = filet(fd, input, check, i);
	layer_of_eggs(tris);
	close(fd);
}
