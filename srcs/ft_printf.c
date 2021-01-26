/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:54:21 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/26 15:33:37 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_adress(t_pf *flags)
{
	char	*str;
	void	*p;

	p = (void *)va_arg(*(flags->ap), unsigned long long);
	str = ft_ulltoa_base((unsigned long long)p, "0123456789abcdef");
	flags->flags |= HASH_FLAG;
	
	return (convert_hex(flags, str));
}

int	print_selector(t_pf *flags)
{
	if (flags->type & C_TYPE)
		return (convert_char(flags));
	if (flags->type & S_TYPE)
		return (convert_str(flags));
	if (flags->type & P_TYPE)
		return (convert_adress(flags));
	if (flags->type & (D_TYPE | I_TYPE))
		return (convert_int(flags));
	if (flags->type & U_TYPE)
		return (convert_uint(flags));
	if (flags->type & X_TYPE)
		return (convert_hex(flags, NULL));
	if (flags->type & N_TYPE && BONUS == 1)
		return (copy_printed_char(flags));
	return (1);
}

int	process_print(const char *str, t_pf *flags)
{
	int	error;

	while (*str != '\0')
	{
		error = 1;
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
	return (flags->printed_char);
}

int	ft_printf(const char *str, ...)
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
