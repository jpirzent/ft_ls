/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:26:13 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/04 15:39:02 by jpirzent         ###   ########.fr       */
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
		if (current->data.name[0] != '.')
			c += current->data.bsize;
		current = current->next;
	}
	free(current);
	return (c);
}
