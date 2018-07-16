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

# define POS(z) tris[i].b[z]

typedef unsigned char	t_byte;

typedef unsigned char	t_bool;

typedef struct			s_entry
{
	struct s_entry	*r;
	struct s_entry	*l;
	struct s_entry	*u;
	struct s_entry	*d;
	struct s_entry	*c;
	char			*n;
	t_byte			s;
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

void					layer_of_eggs(t_piece *tetrimini);
t_bool					death(t_piece *p1, t_piece *p2);
void					fillit(int fd);
t_piece					*parse_piece(char *square);
t_root					*root_init(void);
t_colm					*colm_init(t_root *root, char *name);
t_colo					*colo_init(char *name);
t_one					*one_init(t_entry *colhead, t_one *rowleft);
t_colm					*ith(t_root *root, int i);
void					print_solution(t_one **solution, int k, int sqr);
void					colver(t_entry *col);
void					callback(t_entry *col);
void					cvb(t_entry *row, t_bool cover, void (*f)(t_entry *col),
							t_one **sk);

#endif
