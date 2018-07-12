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

t_piece	*filet(int fd)
{
	fd++;
	fd--;
	return (NULL);
}

void	fillit(int fd)
{
	t_piece	*tetrimini;

	tetrimini = filet(fd);
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
