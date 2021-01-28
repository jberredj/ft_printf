/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:18:33 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/28 13:10:11 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_type.h"
#include "ft_printf.h"

int	type_parser(char *str, t_pf *flags)
{
	if (*str == 'c')
		flags->type |= C_TYPE;
	if (*str == 's')
		flags->type |= S_TYPE;
	if (*str == 'p')
		flags->type |= P_TYPE;
	if (*str == 'd')
		flags->type |= D_TYPE;
	if (*str == 'i')
		flags->type |= I_TYPE;
	if (*str == 'u')
		flags->type |= U_TYPE;
	if (*str == 'x')
		flags->type |= X_TYPE;
	if (*str == 'X')
		flags->type |= X_TYPE | UPPER_TYPE;
	if (*str == '%')
		flags->type |= PERCENT_TYPE;
	if (*str == 'n')
		flags->type |= N_TYPE;
	if (flags->type != 0)
		return (1);
	return (0);
}
