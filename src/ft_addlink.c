/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:35:44 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/20 15:57:38 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fnames	*ft_addlink(t_fnames **start, char *content, struct stat *buff)
{
	t_fnames			*new;
	struct passwd		*pwd;
	struct group		*gid;

	pwd = getpwuid(buff->st_uid);
	gid = getgrgid(buff->st_gid);
	new = *start;
	while (new && new->next)
		new = new->next;
	if (!new)
	{
		*start = ft_memalloc(sizeof(t_fnames));
		(*start)->data.name = ft_strdup(content);
		(*start)->data.time = ft_format_t(ctime(&(buff)->st_ctimespec.tv_sec));
		(*start)->data.rwr = findrwr(buff);
		(*start)->data.links = buff->st_nlink;
		(*start)->data.owner = pwd->pw_name;
		(*start)->data.group = gid->gr_name;
		(*start)->data.fsize = buff->st_size;
		return (*start);
	}
	new->next = ft_memalloc(sizeof(t_fnames));
	new->next->data.name = ft_strdup(content);
	new->next->data.time = ft_format_t(ctime(&(buff)->st_ctimespec.tv_sec));
	new->next->data.rwr = findrwr(buff);
	new->next->data.links = buff->st_nlink;
	new->next->data.owner = pwd->pw_name;
	new->next->data.group = gid->gr_name;
	new->next->data.fsize = buff->st_size;
	return (new->next);
}
