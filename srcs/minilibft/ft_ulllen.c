/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulllen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:27:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:01:43 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

size_t	ft_ulllen(unsigned long long n)
{
	size_t	uint_len;

	uint_len = 0;
	if (n != 0)
	{
		while (n != 0)
		{
			n = n / 10;
			uint_len++;
		}
	}
	else
		uint_len = 1;
	return (uint_len);
}
