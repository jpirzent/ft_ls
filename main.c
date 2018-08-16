/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:48:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/16 17:42:48 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*sd;
	t_fnames		*fn;
	size_t			fc;

	fc = 0;
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
	while ((sd=readdir(dir)) != NULL)
	{
		ft_addlink(&fn, sd->d_name);
		fc++;
	}
	flags(fn, argv[1], fc);
}
