/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:27:02 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/24 15:09:22 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_intlen(int n)
{
	int	int_len;

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
