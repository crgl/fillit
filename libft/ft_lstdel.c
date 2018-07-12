/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:27:28 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/10 14:31:01 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next == NULL)
		ft_lstdelone(alst, del);
	else
	{
		del((*alst)->content, (*alst)->content_size);
		ft_lstdel(&((*alst)->next), del);
		free((*alst));
		*alst = NULL;
	}
}
