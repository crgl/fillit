/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:14:40 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/09 19:16:44 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}
