/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:34:01 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/20 10:29:24 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

int	pf_intlen(int n)
{
	int	int_len;

	int_len = 0;
	while (n != 0)
	{
		n = n / 10;
		int_len++;
	}
	return (int_len);
}


int print_sign(int nbr, t_pf *flags)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', flags->fd);
		flags->printed_char++;
		flags->width--;
	}
	else if (flags->flags & (PLUS_FLAG | SPACE_FLAG))
	{
		if (flags->flags & PLUS_FLAG)
			ft_putchar_fd('+', flags->fd);
		if (flags->flags & SPACE_FLAG)
			ft_putchar_fd(' ', flags->fd);
		flags->printed_char++;
		flags->width--;
	}
	return (0);
}

int process_zero_flag(t_pf *flags)
{
	if (flags->flags & ZERO_FLAG)
	{
		if (flags->precision <= 0)
		{
			flags->precision = flags->width;
			flags->width = 0;
		}
		else
		{
			flags->width -= flags->precision;
			flags->flags &= ~ZERO_FLAG;
		}
		flags->precision_state = SET;
		return (1);
	}
	else if (flags->precision > 0)
		flags->width -= flags->precision;
	return (0);
}

int print_int(t_pf *flags)
{
	int nbr;
	int len;
	
	nbr = va_arg(*(flags->list), int);
	len = pf_intlen(nbr);
	flags->precision -= len;
	flags->width -= len;
	if (nbr < 0)
		flags->width--;
	process_zero_flag(flags);
	if (!(flags->flags & MINUS_FLAG))
		print_width(flags);
	if ((flags->precision_state == SET && flags->precision != 0)
	|| flags->precision_state == NOT_SET)
	{
		print_sign(nbr, flags);
		print_precision(flags);
		ft_putnbr_sign_fd(nbr, flags->fd, 0);
	}
	if (flags->flags & MINUS_FLAG)
		print_width(flags);
	flags->printed_char += len;
	return (0);
}