/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:48:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/06 16:41:21 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*file_join(char *dir, char *filename)
{
	char	*name;
	char	*t;

	if (ft_strcmp(dir, ".") == 0)
		return (filename);
	else
	{
		t = ft_strjoin(dir, "/");
		name = ft_strjoin(t, filename);
		free(t);
	}
	return (name);
}

int				check_idir(char *s)
{
	if (s[0] != '-')
		return (1);
	else
		return (0);
}

static void		print_err(char *s)
{
	ft_printf("ls: %s: %s\n", s, strerror(errno));
	exit(1);
}

int				main(int argc, char **argv)
{
	DIR				*dir;
	t_fnames		*fn;
	char			*filename;

	if (argc == 1 || argv[2] == NULL)
	{
		dir = opendir(".");
		filename = ft_strdup(".");
	}
	else
	{
		if (check_idir(argv[2]) == 1)
		{
			dir = opendir(argv[2]);
			filename = ft_strdup(argv[2]);
		}
		else
		{
			ft_printf("Invalid Input:	only one flag allowed\n");
			exit(1);
		}
	}
	if (dir == NULL)
		print_err(argv[2]);
	fn = read_dir(dir, filename);
	if (argc > 1)
		flags(fn, argv[1]);
	else
		flags(fn, "normal");
	free(filename);
	lstfree(&fn);
	closedir(dir);
}
