/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:18:50 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/29 12:50:43 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ch_sortlink(t_fnames *fn, char *flags)
{
	if (ft_strcmp(flags, "-t") == 0)
		sort_t_list(fn);
	else
		sortlink(fn);
}

void	sortlink(t_fnames *fn)
{
	t_fnames	*sw;
	t_fnames	*tmp;
	t_data		temp_data;
	int		swapped;

	swapped = 1;
	t_fnames	**start = &fn;
	while (swapped)
	{
		printf("\ncurrent list\n");
		flags(*start, "-a");
		printf("\t\tdone\n");
		//printf("start:	%s	||	address:	%p\n", (*start)->data.name, *start);
		swapped = 0;
		tmp = fn;
		sw = fn;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->data.name, tmp->next->data.name) > 0)
			{
				swapped = 1;
				temp_data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = temp_data;

//				sw->data = tmp->data;
//				tmp->data = tmp->next->data;
//				tmp->next->data = sw->data;
			}
			tmp = tmp->next;
		}
	}
}
