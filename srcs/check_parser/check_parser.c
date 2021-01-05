/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:53:12 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 14:51:48 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int check_illegal_combination(t_pf_flags *flags)
{
	if (flags->type & C_TYPE)
		c_type_illegal(flags);
	if (flags->type & S_TYPE)
		s_type_illegal(flags);
	if (flags->type & P_TYPE)
		p_type_illegal(flags);
	if (flags->type & (E_TYPE | F_TYPE | G_TYPE))
		e_f_g_type_illegal(flags);
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

int check_parser(t_pf_flags *flags)
{
	check_illegal_combination(flags);
	if (flags->length != 0)
		length_data_alloc(flags);
	else
		data_alloc(flags);
	return (0);
}