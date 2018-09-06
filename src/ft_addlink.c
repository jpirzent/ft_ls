/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:35:44 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/04 16:23:32 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fnames		*read_dir(DIR *dir, char *filename)
{
	t_fnames	*fn;
	t_dirent	*sd;
	char		*name;

	fn = NULL;
	if (ft_strcmp(filename, ".") != 0)
		while ((sd = readdir(dir)) != NULL)
		{
			name = file_join(filename, sd->d_name);
			ft_addlink(&fn, sd->d_name, name);
			free(name);
		}
	else
		while ((sd = readdir(dir)) != NULL)
			ft_addlink(&fn, sd->d_name, sd->d_name);
	free(sd);
	return (fn);
}

void			ft_addlink(t_fnames **start, char *content, char *filename)
{
	t_fnames			*new;
	struct stat			*buff;

	buff = (struct stat *)malloc(sizeof(struct stat));
	stat(filename, buff);
	new = (*start);
	while (new && new->next)
		new = new->next;
	if (!new)
	{
		*start = (t_fnames *)ft_memalloc(sizeof(t_fnames));
		fill_node(content, buff, *start);
		free(buff);
		return ;
	}
	new->next = (t_fnames *)ft_memalloc(sizeof(t_fnames));
	fill_node(content, buff, new->next);
	free(buff);
}

void			fill_node(char *content, struct stat *buff, t_fnames *start)
{
	struct passwd	*pwd;
	struct group	*gid;

	pwd = getpwuid(buff->st_uid);
	gid = getgrgid(buff->st_gid);
	start->data.name = ft_strdup(content);
	start->data.time = ft_format_t(ctime(&(buff)->st_ctimespec.tv_sec));
	start->data.rwr = findrwr(buff);
	start->data.bsize = (int)buff->st_blocks;
	start->data.links = buff->st_nlink;
	start->data.owner = pwd->pw_name;
	start->data.group = gid->gr_name;
	start->data.fsize = buff->st_size;
}
