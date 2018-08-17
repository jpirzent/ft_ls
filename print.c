/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:07:14 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/17 13:23:03 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printa(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
void	printn(char *s)
{
	if (s[0] != '.')
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}

void	rprintr(t_fnames *fn)
{
	if (fn)
		rprintr(fn->next);
	if (fn)
	{
		printn(fn->name);
	}
}
