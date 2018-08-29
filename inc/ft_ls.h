/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:32:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/29 15:29:43 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <libc.h>
# include <stdio.h> 

typedef struct	s_data
{
	int				bsize;
	char			*rwr;
	unsigned short	links;
	char			*owner;
	char			*group;
	size_t			fsize;
	char			*time;
	char			*name;
	struct s_data	*next;
}				t_data;

typedef struct	s_fnames
{
	t_data			data;
	struct s_fnames	*next;
}				t_fnames;

typedef struct dirent t_dirent;

t_fnames		*ft_addlink(t_fnames **start, char *content, struct stat *buff);

void			flags(t_fnames *fm, char *flags);
void			printa(char *s);
void			printn(char *s);
void			rprintr(t_fnames *fn);
void			printl(t_fnames *fn);
void			sortlink(t_fnames *fn);
void			sort_t_list(t_fnames *fn);
void			ch_sortlink(t_fnames *fn, char *flags);

char			*findrwr(struct stat *buff);
char			*ft_format_t(char *s);

int				ft_blkcnt(t_fnames **fn);
#endif
