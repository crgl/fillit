/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:26:14 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 19:35:14 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	char	*scat;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	scat = ft_strnew(l1 + l2);
	if (scat == NULL)
		return (NULL);
	while (i < l1)
		scat[i++] = *s1++;
	while (i < l1 + l2)
		scat[i++] = *s2++;
	return (scat);
}
