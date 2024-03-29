/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:27:44 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/04 15:46:47 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_t_list(t_fnames *fn)
{
	t_fnames	*tmp;
	t_data		temp_data;
	int			swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = fn;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->data.time, tmp->next->data.time) < 0)
			{
				swapped = 1;
				temp_data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = temp_data;
			}
			tmp = tmp->next;
		}
	}
}
