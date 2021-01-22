/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:54:21 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 19:16:22 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_selector(t_pf *flags)
{
	int ret;

	ret = 1;
	/*if (flags->type & C_TYPE)
		print_char(flags);
	if (flags->type & S_TYPE)
		print_string(flags);
	if (flags->type & P_TYPE)
		print_adress(flags);*/
	if (flags->type & (D_TYPE | I_TYPE))
		ret = convert_int(flags);
	if (flags->type & U_TYPE)
		ret = convert_uint(flags);
	/*if (flags->type & X_TYPE)
		print_hex(flags);*/
	if (flags->type & N_TYPE && BONUS == 1)
		copy_printed_char(flags);
	return (ret);
}

int process_print(const char *str, t_pf *flags)
{
	int end;
	int error;

	end = 0;
	while (1)
	{
		error = 1;
		if (*str == '\0')
			break;
		if (*str == '%' && (*str + 1) != '\0')
		{
			str = main_parser((char *)str, flags);
			check_parser(flags);
			error = print_selector(flags);
			clear_flags(flags);	
		}
		if (error == 1)
		{
			add_to_buffer((char*)str, 1, flags);
			str++;
		}	
		if (error == -1)
			return (-1);
	}
	print_buffer(flags);
	return(flags->printed_char);
}

int ft_printf(const char *str, ...)
{
	va_list	ap;
	t_pf	flags;
	int		printed_char;

	va_start(ap, str);
	init_flags(&flags);
	flags.ap = &ap;
	printed_char = process_print(str, &flags);
	va_end(ap);
	return (printed_char);
}