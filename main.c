/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:48:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/17 16:32:02 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dir;
	t_dirent		*sd;
	t_fnames		*fn;

	fn = NULL;
//	if (argc == 1)
		dir = opendir(".");
//	else
//		dir = opendir(argv[argc - 1]);
	if (dir == NULL)
	{
		printf("ls: %s: No such file or directory.\n", argv[argc - 1]);
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		ft_addlink(&fn, sd->d_name);
	}
	sortlink(fn);
	if (argc > 1)
		flags(fn, argv[1]);
	else
		flags(fn, "normal");
}
