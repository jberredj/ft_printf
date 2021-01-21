/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:31:49 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/20 17:44:22 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_width(t_pf *flags)
{
	while (flags->width > 0)
	{
		if (flags->flags & ZERO_FLAG)
			ft_putchar_fd('0', flags->fd);
		else
			ft_putchar_fd(' ', flags->fd);
		flags->width--;
		flags->printed_char++;
	}
	return (0);
}