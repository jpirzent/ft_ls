/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:36:10 by jpirzent          #+#    #+#             */
/*   Updated: 2018/06/10 10:40:26 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
}