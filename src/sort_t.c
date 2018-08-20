/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:27:44 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/20 15:22:16 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_t_list(t_fnames *fn)
{
	t_fnames	*tmp;
	t_fnames	*sw;
	int			swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = fn;
		sw = fn;
		while (tmp->next)
		{
			if (ft_strcmp(&(tmp->data.time[7]), &(tmp->next->data.time[7])) < 0)
			{
				swapped = 1;
				sw->data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = sw->data;
			}
			tmp = tmp->next;
		}
	}
}
