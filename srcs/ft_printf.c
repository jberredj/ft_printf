/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:54:21 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/18 11:41:14 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int print_char(t_pf *flags)
{
	// no 0# + flags
	// no precision
	char c;

	if (flags->type & PERCENT_TYPE)
		c = '%';
	else		
		c = (char)va_arg(*(flags->list), int);
	flags->width--;
	if (!(flags->flags & MINUS_FLAG))
		print_width(flags);
	write(flags->fd, &c, 1);
	flags->printed_char++;
	if (flags->flags & MINUS_FLAG)
		print_width(flags);
	return (1);
}

int print_string(t_pf *flags)
{
	// no 0# + flags
	char	*str;
	int		len;

	str = va_arg(*(flags->list), char *);
	if (flags->precision_state == NOT_SET)
		len = ft_strlen(str);
	else
		len = flags->precision;
	flags->width -= len;
	if (!(flags->flags & MINUS_FLAG))
		print_width(flags);
	write(flags->fd, str, len);
	flags->printed_char += len;
	if (flags->flags & MINUS_FLAG)
		print_width(flags);
	return (1);
}

int print_adress(t_pf *flags)
{
	// no 0# + flags
	// no precision
	void *p;
	int len;

	p = va_arg(*(flags->list), void *);
	if (p != NULL)
		len = ft_intlen_base((int)p, 16) + 2;
	else
		len = 5;
	flags->width -= len;
	if (!(flags->flags & MINUS_FLAG))
		print_width(flags);
	if (p != NULL)
	{
		ft_putstr_fd("0x", flags->fd);
		ft_putnbr_base_fd((int)p, "0123456789abcdef", flags->fd);
	}
	else
		ft_putstr_fd("(nil)", flags->fd);
	flags->printed_char += len;
	if (flags->flags & MINUS_FLAG)
		print_width(flags);
	return (0);
}

int print_selector(t_pf *flags)
{
	//if (flags->type & (D_TYPE | I_TYPE))
	//	print_int(flags);
	if (flags->type & C_TYPE)
		print_char(flags);
	if (flags->type & S_TYPE)
		print_string(flags);
	if (flags->type & P_TYPE)
		print_adress(flags);
	return (0);
}

int process_print(const char *str, t_pf *flags)
{
	int end;
	int error;

	end = 0;
	error = 0;
	while (1)
	{
		if (*str == '\0')
			break;
		if (*str == '%' && (*str + 1) != '\0')
		{
			str = main_parser((char *)str, flags);
			error = check_parser(flags);
			error = print_selector(flags);
			clear_flags(flags);	
		}
		if (error != 1)
		{
			ft_putchar_fd(*str, flags->fd);
			flags->printed_char++;
		}
		if (error == -2)
			return (-1);
		str++;
	}
	return(flags->printed_char);
}

int ft_printf(const char *str, ...)
{
	va_list	list;
	t_pf	flags;
	int		printed_char;

	va_start(list, str);
	init_flags(&flags);
	flags.list = &list;
	printed_char = process_print(str, &flags);
	va_end(list);
	return (printed_char);
}