/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:08:22 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 11:33:50 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int stpd, size_t n)
{
	unsigned char	c;
	size_t			i;

	c = (unsigned char)stpd;
	i = 0;
	while (i < n)
		*((unsigned char *)ptr + i++) = c;
	return (ptr);
}
