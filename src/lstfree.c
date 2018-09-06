/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:59:32 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/06 14:47:55 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	lst_freeone(t_fnames **fn)
{
	t_fnames *temp;

	temp = *fn;
	*fn = (*fn)->next;
	free(temp->data.name);
	free(temp->data.time);
	free(temp->data.rwr);
	free(temp);
}

void	lstfree(t_fnames **fn)
{
	if (*fn)
	{
		lstfree(&(*fn)->next);
		lst_freeone(fn);
	}
}
