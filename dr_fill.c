/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:57:01 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/14 14:27:20 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

t_piece	g_piece[20] = {
	{1, 4, {{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
	{4, 1, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}},
	{2, 2, {{0, 0}, {1, 0}, {0, 1}, {1, 1}}},
	{3, 2, {{0, 0}, {1, 0}, {2, 0}, {1, 1}}},
	{3, 2, {{1, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{2, 3, {{1, 0}, {0, 1}, {1, 1}, {1, 2}}},
	{2, 3, {{0, 0}, {0, 1}, {1, 1}, {0, 2}}},
	{3, 2, {{1, 0}, {2, 0}, {0, 1}, {1, 1}}},
	{2, 3, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}},
	{3, 2, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}},
	{2, 3, {{1, 0}, {0, 1}, {1, 1}, {0, 2}}},
	{2, 3, {{1, 0}, {1, 1}, {0, 2}, {1, 2}}},
	{2, 3, {{0, 0}, {1, 0}, {0, 1}, {0, 2}}},
	{3, 2, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{3, 2, {{0, 0}, {1, 0}, {2, 0}, {2, 1}}},
	{2, 3, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}},
	{2, 3, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}},
	{3, 2, {{0, 0}, {1, 0}, {2, 0}, {0, 1}}},
	{3, 2, {{2, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{0, 0, {{0, 0}, {0, 0}, {0, 0}, {0, 0}}}
};

void	which_help(t_point *hashes, t_byte *xmin, t_byte *ymin)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (hashes[i].x < *xmin)
			*xmin = hashes[i].x;
		if (hashes[i].y < *ymin)
			*ymin = hashes[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		hashes[i].x -= *xmin;
		hashes[i].y -= *ymin;
		i++;
	}
}

t_piece	*which_piece(t_point *hashes)
{
	size_t	j;
	size_t	i;
	t_byte	xmin;
	t_byte	ymin;

	j = 0;
	i = 0;
	xmin = 4;
	ymin = 4;
	which_help(hashes, &xmin, &ymin);
	while (j < END)
	{
		i = 0;
		while (i < 4 && hashes[i].x == g_piece[j].b[i].x &&
				hashes[i].y == g_piece[j].b[i].y)
			i++;
		if (i == 4)
			return (&g_piece[j]);
		j++;
	}
	return (NULL);
}

t_piece	*parse_piece(char *square)
{
	size_t	i;
	t_byte	j;
	t_point	hashes[4];

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (square[i] == '#' && (i + 1) % 5 != 0)
		{
			if (j < 4)
				hashes[j++] = (t_point){i % 5, i / 5};
			else
				return (NULL);
		}
		else if (square[i] != '\n' && (i + 1) % 5 == 0)
			return (NULL);
		else if (square[i] != '.' && (i + 1) % 5 != 0)
			return (NULL);
		i++;
	}
	if (j < 4)
		return (NULL);
	return (which_piece(hashes));
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tris_list.fillit");
		return (argc);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	else
		fillit(fd);
	return (0);
}
