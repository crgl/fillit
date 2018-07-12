/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:40:56 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/10 19:55:34 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src - dst >= 0)
	{
		while (i < n)
		{
			*((t_byte *)dst + i) = *((t_byte *)src + i);
			i++;
		}
		return (dst);
	}
	while (i < n)
	{
		*((t_byte *)dst + n - i - 1) = *((t_byte *)src + n - i - 1);
		i++;
	}
	return (dst);
}
