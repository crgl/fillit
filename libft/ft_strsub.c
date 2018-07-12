/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:20:14 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 19:36:32 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ssub;
	size_t	i;

	ssub = ft_strnew(len);
	if (ssub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ssub[i] = s[(size_t)start + i];
		i++;
	}
	return (ssub);
}
