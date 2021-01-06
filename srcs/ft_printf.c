/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:54:21 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/06 14:32:56 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int print_selector(t_pf *flags)
{
	if (flags->type & (D_TYPE | I_TYPE))
		print_int(flags);
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
			flags->printed_char += ft_putchar_fd(*str, flags->fd);
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