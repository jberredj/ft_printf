/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:27:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:05:20 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

size_t	ft_lllen(long long n)
{
	size_t	int_len;

	int_len = 0;
	if (n <= 0)
		int_len = 1;
	while (n != 0)
	{
		n = n / 10;
		int_len++;
	}
	return (int_len);
}
