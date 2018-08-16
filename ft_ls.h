/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:32:16 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/16 17:52:50 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h> 

typedef struct	s_fnames
{
	char			*name;
	struct s_fnames	*next;
}				t_fnames;

t_fnames		*ft_addlink(t_fnames **start, char *content);

void			flags(t_fnames *fm, char *flags, size_t fc);


#endif
