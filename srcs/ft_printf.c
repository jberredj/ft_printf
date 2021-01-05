/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:54:21 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 12:10:41 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int process_print(const char *str, t_pf_flags *flags)
{
	int end;
	int printed_char;

	end = 0;
	printed_char = 0;
	while (end == 0)
	{
		flags->printed_char = printed_char;
		if (*str == '\0')
			end = 1;
		if (*str == '%' && (*str + 1) != '\0')
		{
			str++;
			str = main_parser(str, flags);
			check_parser(flags);
			printed_char += print_selector(flags);	
		}
		else
			printed_char += ft_putchar_fd(*str, flags->fd);
		str++;
	}
	return(printed_char);
}

int ft_printf(const char *str, ...)
{
	va_list		list;
	t_pf_flags	flags;
	int			printed_char;

	va_start(list, str);
	init_flags(&flags);
	flags.list = &list;
	printed_char = process_print(str, &flags);
	va_end(list);
	return (printed_char);
}