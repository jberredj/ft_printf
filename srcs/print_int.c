/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:30:00 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/07 14:33:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_nbr_fd(int n, int fd)
{
	unsigned int	us_n;
	int				len;

	len = ft_intlen(n);
	if (n < 0)
	{
		us_n = (unsigned int)n;
		us_n = -us_n;
	}
	else
		us_n = (unsigned int)(n);
	if (us_n >= 10)
	{
		print_nbr_fd(us_n / 10, fd);
	}
	ft_putchar_fd((char)(us_n % 10 + '0'), fd);
	return (n);
}

int int_precision(int nbr, t_pf *flags)
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
	print_nbr_fd(nbr, flags->fd);
	return (0);
}

int int_sign(int nbr, t_pf *flags)
{
	if (nbr < 0)
		ft_putchar_fd('-', flags->fd);
	if (flags->flags & PLUS_FLAG && nbr > 0)
	{
		ft_putchar_fd('+', flags->fd);
	}
	int_precision(nbr, flags);
	return (0);
}

int	pf_int_len(int n)
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

int print_int(t_pf *flags)
{
	int nbr;

	nbr = va_arg(*(flags->list), int);
	flags->precision -= pf_int_len(nbr);
	flags->width -= pf_int_len(nbr);
	return (0);
}