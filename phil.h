/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:05:11 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/11 11:24:48 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

typedef	struct			s_point
{
	t_byte		x;
	t_byte		y;
}

typedef enum			e_type
{
	I,
	IH,
	O,
	T,
	TT,
	TL,
	TR,
	S,
	SV,
	Z,
	ZV,
	J,
	JT,
	JL,
	JR,
	L,
	LT,
	LL,
	LR
}						t_type;

typedef struct			s_piece
{
	t_byte		width;
	t_byte		height;
	t_point		b[4];
}						t_piece;

global s_piece[]	g_piece = {
	{1, 4, {{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
	{4, 1, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}},
	{2, 2, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
	{3, 2, {{0, 0}, {1, 0}, {1, 1}, {2, 0}}},
	{3, 2, {{1, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{2, 3, {{1, 0}, {0, 1}, {1, 1}, {1, 2}}},
	{2, 3, {{0, 0}, {0, 1}, {1, 1}, {0, 2}}},
	{3, 2, {{1, 0}, {0, 1}, {1, 1}, {2, 0}}},
	{2, 3, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}},
	{3, 2, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{2, 3, {{1, 0}, {0, 1}, {1, 1}, {0, 2}}},
	{2, 3, {{1, 0}, {1, 1}, {1, 2}, {0, 2}}},
	{2, 3, {{0, 0}, {0, 1}, {0, 2}, {1, 0}}},
	{3, 2, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{3, 2, {{0, 0}, {1, 0}, {2, 0}, {2, 1}}},
	{2, 3, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}},
	{2, 3, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}},
	{3, 2, {{0, 0}, {1, 0}, {2, 0}, {0, 1}}},
	{3, 2, {{0, 1}, {1, 1}, {2, 1}, {2, 0}}},
};

#endif