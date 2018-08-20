/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:48:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/20 16:47:42 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct stat		*buff;
	t_dirent		*sd;
	t_fnames		*fn;

	fn = NULL;
	if (argc == 1 || argv[2] == NULL)
		dir = opendir(".");
	else
		dir = opendir(argv[2]);
	if (dir == NULL)
	{
		ft_printf("ls: %s: No such file or directory.\n", argv[2]);
		exit(1);
	}
	buff = (struct stat *)malloc(sizeof(struct stat));
	while ((sd = readdir(dir)) != NULL)
	{
		stat(sd->d_name, buff);
		ft_addlink(&fn, sd->d_name, buff);
	}
	if (argc > 1)
	{
		ch_sortlink(fn, argv[1]);
		flags(fn, argv[1]);
	}
	else
		flags(fn, "normal");
}
