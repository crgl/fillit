/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:07:47 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 19:11:22 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*snew;

	if (s == NULL)
		return (NULL);
	snew = ft_strnew(ft_strlen(s));
	if (snew == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		snew[i] = f(i, s[i]);
		i++;
	}
	return (snew);
}
