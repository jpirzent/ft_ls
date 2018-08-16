/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pudec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:07:48 by jpirzent          #+#    #+#             */
/*   Updated: 2018/07/16 09:57:31 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pudec(long l)
{
	if (l < 0)
		l = UINT_MX + l;
	ft_putnbrl(l);
}