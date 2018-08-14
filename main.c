/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:48:54 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/14 15:21:46 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*sd;
	char			*s;
	const char		*flags = "-a";

	if (argc == 1)
		dir = opendir(".");
	else
		dir = opendir(argv[argc - 1]);
	if (dir == NULL)
	{
		printf("ls: %s: No such file or directory.\n", argv[1]);
		exit(1);
	}
	while ((sd=readdir(dir)) != NULL)
	{
		s = sd->d_name;
		if (argv[1] == flags)
			printf("%s\t", s);
		else if (s[0] != '.')
			printf("%s\t", s);
	}
	printf("\n");
}
