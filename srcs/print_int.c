/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:34:01 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 19:28:49 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

int print_sign(int nbr, t_pf *flags)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', flags->fd);
		flags->printed_char++;
		flags->width--;
	}
	else
	{
		if (flags->flags & PLUS_FLAG)
			{
				ft_putchar_fd('+', flags->fd);
				flags->printed_char++;
				flags->width--;
			}
		if (flags->flags & SPACE_FLAG)
			{
				ft_putchar_fd(' ', flags->fd);
				flags->printed_char++;
				flags->width--;
			}
	}
	return (0);
}

int print_int(t_pf *flags)
{
	int nbr;
	int len;
	
	nbr = va_arg(*(flags->list), int);
	len = ft_intlen(nbr);
	flags->precision -= len;
	flags->width -= len;
	if (flags->precision > 0)
		flags->width -= flags->precision;
	if (!(flags->flags & MINUS_FLAG))
		print_width(flags);
	print_sign(nbr, flags);
	print_precision(flags);
	ft_put_unbr_fd(nbr, flags->fd);
	flags->printed_char += len;
	flags->flags &= ~ZERO_FLAG;
	if (flags->flags & MINUS_FLAG)
		print_width(flags);
	return (0);
}