/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:18:50 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/17 12:40:52 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortlink(t_fnames *fn)
{
	t_fnames *tmp;
	char	*s;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = fn;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				swapped = 1;
				s = tmp->name;
				tmp->name = tmp->next->name;
				tmp->next->name = s;
			}
			tmp = tmp->next;
		}
	}
}
