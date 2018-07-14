/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:57:01 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/11 11:21:59 by cgleason         ###   ########.fr       */
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

void	display_usage(void)
{
	ft_putendl("usage: ./fillit tetrimino_list.fillit");
}

t_piece	*which_piece(t_point *hashes)
{
	size_t	i;
	size_t	j;
	t_byte	xmin;
	t_byte	ymin;

	i = 0;
	j = 0;
	xmin = 4;
	ymin = 4;
	while (i < 4)
	{
		if (hashes[i].x < xmin)
			xmin = hashes[i].x;
		if (hashes[i].y < ymin)
			ymin = hashes[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		hashes[i].x -= xmin;
		hashes[i].y -= ymin;
		i++;
	}
	j = 0;
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

t_piece	*filet(int fd)
{
	t_piece	temp[27];
	size_t	i;
	t_piece	*output;
	t_piece	*input;
	int		check;

	i = 0;
	input = &g_piece[I];
	check = 20;
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
	while   (i)
	{
		i--;
		output[i] = temp[i];
	}
	return (output);
}

void	fillit(int fd)
{
	t_piece	*tetrimini;

	tetrimini = filet(fd);
	layer_of_eggs(tetrimini);
	close(fd);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		display_usage();
		return (argc);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	else
		fillit(fd);
	return (0);
}
