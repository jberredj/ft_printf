/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:18:33 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 17:54:23 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf_parser.h"
#include "parser_type.h"

int	type_parser_next(char *str, t_pf *flags)
{
	if (*str == 'F')
		flags->type |= F_TYPE | UPPER_TYPE;
	if (*str == 'e')
		flags->type |= E_TYPE;
	if (*str == 'E')
		flags->type |= E_TYPE | UPPER_TYPE;
	if (*str == 'g')
		flags->type |= G_TYPE;
	if (*str == 'G')
		flags->type |= G_TYPE | UPPER_TYPE;
	if (*str == 'p')
		flags->type |= P_TYPE;
	if (*str == 'n')
		flags->type |= N_TYPE;
	if (*str == '%')
		flags->type |= PERCENT_TYPE;
	if (flags->type != 0)
		return (1);
	return (0);
}

int	type_parser(char *str, t_pf *flags)
{
	if (*str == 'd')
		flags->type |= D_TYPE;
	if (*str == 'i')
		flags->type |= I_TYPE;
	if (*str == 'x')
		flags->type |= X_TYPE;
	if (*str == 'X')
		flags->type |= X_TYPE | UPPER_TYPE;
	if (*str == 'u')
		flags->type |= U_TYPE;
	if (*str == 'c')
		flags->type |= C_TYPE;
	if (*str == 's')
		flags->type |= S_TYPE;
	if (*str == 'f')
		flags->type |= F_TYPE;
	return (type_parser_next(str, flags));
}
