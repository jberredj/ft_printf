/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:38:59 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 10:53:25 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

int base_selector(char **str, t_pf *flags)
{
	if (flags->type & UPPER_TYPE)
		*str = "0123456789ABCDEF";
	else
		*str = "0123456789abcdef";
	return (0);
}

int print_zero_x(t_pf *flags)
{
	if (flags->flags & HASH_FLAG)
	{
		if (flags->type & UPPER_TYPE)
			ft_putstr_fd("0X", flags->fd);
		else
			ft_putstr_fd("0X", flags->fd);
		flags->printed_char += 2;
	}
	return (0);
}

int print_hex(t_pf *flags)
{
	long long nbr;
	int len;
	char *base;
	
	base = "";
	nbr = va_arg(*(flags->ap), long long);
	len = ft_lllen_base(nbr, 16);
	flags->precision -= len;
	flags->width -= len;
	if (flags->precision > 0)
		flags->width -= flags->precision;
	if (flags->flags & HASH_FLAG)
		flags->width -= 2;
	if (!(flags->flags & MINUS_FLAG))
		print_width(flags);
	print_zero_x(flags);
	print_precision(flags);
	base_selector(&base, flags);
	ft_putnbr_base_fd(nbr, base, flags->fd);
	flags->printed_char += len;
	if (flags->flags & MINUS_FLAG)
		print_width(flags);
	return (0);
}