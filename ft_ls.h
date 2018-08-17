/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:32:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/17 13:21:40 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h> 

typedef struct	s_fnames
{
	char			*name;

	struct s_fnames	*next;
}				t_fnames;

typedef struct dirent t_dirent;

t_fnames		*ft_addlink(t_fnames **start, char *content);

void			flags(t_fnames *fm, char *flags);
void			printa(char *s);
void			printn(char *s);
void			rprintr(t_fnames *fn);
void			sortlink(t_fnames *fn);
#endif
