/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:40:10 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/10 19:19:02 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*strim;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s != '\0')
		s++;
	while (s[i] != '\0')
		i++;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
	{
		if (i == 0)
			return (ft_strnew(0));
		i--;
	}
	strim = ft_strnew(i + 1);
	if (strim == NULL)
		return (NULL);
	ft_memset((void *)strim, 32, i + 1);
	i = 0;
	while (strim[i] != '\0')
		strim[i++] = *s++;
	return (strim);
}
