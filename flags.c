/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:07:57 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/16 17:52:18 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flags(t_fnames *fn, char *flag, size_t fc)
{
	int		i;

	i = 0;
	if (ft_strcmp(flag, "-a") == 0)
	{
		if (fc > 4)
		{
			while (fn)
			{
				printf("%s\t", fn->name);
				fn = fn->next;
				i++;
				if (i == 4 && fn->next != NULL)
				{
					i = 0;
					printf("\n");
				}
			}
		}
		else
		{
			while (fn)
			{
			printf("%s\t", fn->name);
			fn = fn->next;
			}
		}
		printf("\n");
	}
}
