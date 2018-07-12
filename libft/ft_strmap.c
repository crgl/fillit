/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:02:29 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 19:07:33 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*snew;
	int		i;

	if (s == NULL)
		return (NULL);
	snew = ft_strnew(ft_strlen(s));
	if (snew == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
		snew[i++] = f(*s++);
	return (snew);
}
