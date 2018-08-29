/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:26:13 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/29 15:32:23 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_blkcnt(t_fnames **fn)
{
	int			c;
	t_fnames	*current;
	
	c = 0;
	current = *fn;
	while (current)
	{
		c += current->data.bsize;
		current = current->next;
	}
	return (c);
}
