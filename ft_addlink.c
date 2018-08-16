/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:35:44 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/16 11:32:30 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fnames	*ft_addlink(t_fnames **start, char *content)
{
	t_fnames	*new;

	new = *start;
	while (new && new->next)
		new = new->next;
	if (!new)
	{
		*start = ft_memalloc(sizeof(t_fnames));
		(*start)->name = ft_strdup(content);
		return (*start);
	}
	new->next = ft_memalloc(sizeof(t_fnames));
	new->next->name = ft_strdup(content);
	return (new->next);
}
