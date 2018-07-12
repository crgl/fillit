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
#include "libft.h"

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
	t_piece	couldbe;
	size_t	i;
	t_byte	j;
	t_point	hashes[4]

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (square[i] == '#' && (i + 1) % 5 != 0)
		{
			if (j < 4)
				hashes[j++] = {i % 5, i / 5}
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

t_piece	*parse_square(int fd)
{
	char	square[20]
	char	c[1];
	int		check;

	check = read(fd, square, 20)
	if (check == 20)
	{
		check = read(fd, c, 1);
		if (c == '\n' || check = 0)
		{
			return (parse_piece(square));
		}
		return (NULL);
	}
	else if (check == 0)
		return (&g_piece[END]);
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
			if (p1->b[i] != p2->b[i])
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

	i = 0;
	input = &g_piece[I];
	while (!(death(&input, &g_piece[END])))
	{
		if (i == 26)
			return (NULL);
		input = parse_square(fd);
		if (input == NULL)
			return (NULL);
		temp[i++] = *input;
	}
	temp[i] = g_piece[END];
	if (i < 2)
		return (NULL);
	output = (t_piece *)malloc(i * sizeof(t_piece));
	output[--i] = g_piece[END];
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
	char	*box;

	tetrimini = filet(fd);
	box = layer_of_eggs(tetrimini);
	ft_putstr(box);
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
