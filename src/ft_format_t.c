/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:49:15 by jpirzent          #+#    #+#             */
/*   Updated: 2018/08/20 15:56:44 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_format_t(char *s)
{
	char	*tmp;
	int		i;
	int		k;

	tmp = (char *)malloc(sizeof(char) * 12);
	i = 4;
	k = 0;
	while (s[i] && k < 12)
	{
		tmp[k] = s[i];
		k++;
		i++;
	}
	tmp[k] = '\0';
	return (tmp);
}
