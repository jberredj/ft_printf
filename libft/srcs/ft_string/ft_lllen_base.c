/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:52:04 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 10:03:07 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_lllen_base(long long n, int base)
{
	long long	int_len;

	if (base <= 2)
		return (-1);
	int_len = 0;
	if (n <= 0)
		int_len = 1;
	while (n != 0)
	{
		n = n / base;
		int_len++;
	}
	return (int_len);
}
