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

typedef enum	e_type
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
}				t_type;

typedef struct	s_piece
{
	t_type		type;
}				t_piece;

#endif
