/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:53:12 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 10:52:54 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int check_illegal_combination(t_pf *flags)
{
	if (flags->type & C_TYPE)
		c_type_illegal(flags);
	if (flags->type & S_TYPE)
		s_type_illegal(flags);
	if (flags->type & P_TYPE)
		p_type_illegal(flags);
	if (flags->type & (D_TYPE | I_TYPE))
		d_i_type_illegal(flags);
	if (flags->type & U_TYPE)
		u_type_illegal(flags);
	if (flags->type & N_TYPE)
		n_type_illegal(flags);
	if (flags->type & X_TYPE)
		x_type_illegal(flags);
	flag_illegal(flags);
	return (0);
}

int check_parser(t_pf *flags)
{
	if (flags->type == 0)
		return (-1);
	check_illegal_combination(flags);
	if (flags->type & PERCENT_TYPE)
		flags->type |= C_TYPE;
	if (flags->width_state == VAR_VALUE)
	{
		flags->width = va_arg(*(flags->ap), int);
		flags->width_state = SET;
	}
	if (flags->precision_state == VAR_VALUE)
	{
		flags->precision = va_arg(*(flags->ap), int);
		flags->precision_state = SET;
	}
	return (1);
}