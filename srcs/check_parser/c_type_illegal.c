/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:21:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 13:01:00 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_type_illegal(t_pf *flags)
{
	/*flags->flags &= ~ ZERO_FLAG;*/
	flags->flags &= ~ HASH_FLAG;
	flags->flags &= ~ PLUS_FLAG;
	flags->flags &= ~ SPACE_FLAG;
	if (flags->precision_state != NOT_SET)
		(void)va_arg(*(flags->ap), int);
	flags->precision = 0;
	flags->precision_state = NOT_SET;
	return (0);
}
