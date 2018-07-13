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
# include "libft.h"

# define TRUE 1
# define FALSE 0

typedef unsigned char	t_byte;

typedef unsigned char	t_bool;

typedef struct			s_entry
{
	struct s_entry	*R;
	struct s_entry	*L;
	struct s_entry	*U;
	struct s_entry	*D;
	struct s_entry	*C;
	char			*N;
	t_byte			S;
}						t_entry;

typedef t_entry			t_root;
typedef t_entry			t_colm;
typedef t_entry			t_colo;
typedef t_entry			t_one;

typedef	struct			s_point
{
	t_byte		x;
	t_byte		y;
}						t_point;

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
	LR,
	END
}						t_type;

typedef struct			s_piece
{
	t_byte		width;
	t_byte		height;
	t_point		b[4];
}						t_piece;

t_piece					g_piece[20];

void	layer_of_eggs(t_piece *tetrimini);
t_bool	death(t_piece *p1, t_piece *p2);

#endif
