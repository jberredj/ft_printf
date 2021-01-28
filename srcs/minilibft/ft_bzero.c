/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:55:51 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 15:56:11 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uchar_s;

	uchar_s = (unsigned char*)s;
	while (n-- > 0)
		*uchar_s++ = '\0';
}
