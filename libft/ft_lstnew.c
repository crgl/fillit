/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgleason <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:14:46 by cgleason          #+#    #+#             */
/*   Updated: 2018/07/10 18:12:54 by cgleason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*content_cpy;
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	*new = (t_list){NULL, 0, NULL};
	if (content == NULL)
		return (new);
	content_cpy = ft_memalloc(content_size);
	if (content_cpy == NULL)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(content_cpy, content, content_size);
	new->content_size = content_size;
	new->content = content_cpy;
	return (new);
}
