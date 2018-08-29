/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:07:57 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/29 12:39:41 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flags(t_fnames *fn, char *flag)
{
	if (ft_strcmp(flag, "-a") == 0)
		while (fn)
		{
		//	printf("fn->name:	%s fn->address:	%p\n", fn->data.name, fn);
			printa(fn->data.name);
			fn = fn->next;
		}
	else if (ft_strcmp(flag, "normal") == 0 || ft_strcmp(flag, "ls") == 0)
		while (fn)
		{
			printn(fn->data.name);
			fn = fn->next;
		}
	else if (ft_strcmp(flag, "-r") == 0)
		rprintr(fn);
	else if (ft_strcmp(flag, "-t") == 0)
		while (fn)
		{
			printn(fn->data.name);
			fn = fn->next;
		}
	else if (ft_strcmp(flag, "-l") == 0)
		while (fn)
		{
			printl(fn);
			fn = fn->next;
		}
	else
		ft_printf("ls:\tillegal option\nusage:\tft_ls [-alrt] [file ...]\n");
}
