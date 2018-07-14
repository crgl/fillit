/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:38:10 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/10 19:46:54 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	strn[12];
	size_t	i;
	int		pow;
	char	*out;

	i = 0;
	if (n < 0)
		strn[i++] = '-';
	else if (n > 0)
		n *= -1;
	else
		return (ft_memset(ft_strnew(1), '0', 1));
	pow = -1;
	while (pow >= n / 10)
		pow *= 10;
	while (pow != 0)
	{
		strn[i++] = '0' + n / pow;
		n %= pow;
		pow /= 10;
	}
	strn[i] = '\0';
	out = ft_strdup(strn);
	return (out);
}
