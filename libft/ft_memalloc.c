/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:07:52 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 14:12:04 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = malloc(size);
	if (res == NULL)
		return (res);
	while (i < size)
		*((unsigned char *)res + i++) = (unsigned char)0;
	return (res);
}
