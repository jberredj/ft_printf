/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:21:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:37:13 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_parser.h"

void	c_type_illegal(t_pf *flags)
{
	flags->flags &= ~HASH_FLAG;
	flags->flags &= ~PLUS_FLAG;
	flags->flags &= ~SPACE_FLAG;
	if (flags->precision_state == VAR_VALUE)
		(void)va_arg(*(flags->ap), int);
	flags->precision = 0;
	flags->precision_state = NOT_SET;
}
