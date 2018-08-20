/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:07:14 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/20 16:12:47 by jpirzent         ###   ########.fr       */
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
		printn(fn->data.name);
}

void	printl(t_fnames *fn)
{
	if (fn->data.name[0] != '.')
	{
		ft_putstr(fn->data.rwr);
		ft_putchar(' ');
		ft_putnbr(fn->data.links);
		ft_putchar('\t');
		ft_putstr(fn->data.owner);
		ft_putchar(' ');
		ft_putstr(fn->data.group);
		ft_putchar(' ');
		ft_putnbr(fn->data.fsize);
		ft_putchar('\t');
		ft_putstr(fn->data.time);
		ft_putchar(' ');
		ft_putstr(fn->data.name);
		ft_putchar('\n');
	}
}
