/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:16:48 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 17:21:35 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

int print_precision(t_pf *flags)
{
	if (flags->precision_state == SET)
	{
	while (flags->precision > 0)
		{
			ft_putchar_fd('0', flags->fd);
			flags->precision--;
			flags->printed_char++;
		}
	}
	return (0);
}