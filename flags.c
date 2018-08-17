/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:07:57 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/17 13:23:24 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flags(t_fnames *fn, char *flag)
{
	if (ft_strcmp(flag, "-a") == 0)
	{
		while (fn)
		{
			printa(fn->name);
			fn = fn->next;
		}
	}
	else if (ft_strcmp(flag, "normal") == 0)
		while (fn)
		{
			printn(fn->name);
			fn = fn->next;
		}
	else if (ft_strcmp(flag, "-r") == 0)
	{
		rprintr(fn);
	}
}
