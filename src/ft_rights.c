/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:58:11 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/20 16:07:14 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*findrwr(struct stat *buff)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 9);
	tmp[0] = (S_ISDIR(buff->st_mode) ? 'd' : '-');
	tmp[1] = (buff->st_mode & S_IRUSR ? 'r' : '-');
	tmp[2] = (buff->st_mode & S_IWUSR ? 'w' : '-');
	tmp[3] = (buff->st_mode & S_IXUSR ? 'x' : '-');
	tmp[4] = (buff->st_mode & S_IRGRP ? 'r' : '-');
	tmp[5] = (buff->st_mode & S_IWGRP ? 'w' : '-');
	tmp[6] = (buff->st_mode & S_IXGRP ? 'x' : '-');
	tmp[7] = (buff->st_mode & S_IROTH ? 'r' : '-');
	tmp[8] = (buff->st_mode & S_IWOTH ? 'w' : '-');
	tmp[9] = (buff->st_mode & S_IXOTH ? 'x' : '-');
	return (tmp);
}
