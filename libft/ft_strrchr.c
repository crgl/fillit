/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:22:59 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 16:15:35 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + res));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			res = i;
		i++;
	}
	if (s[res] == '\0')
		return (NULL);
	return ((char *)(s + res));
}
