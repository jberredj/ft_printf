/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:30:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/24 00:14:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int	n_type_illegal(t_pf *flags)
{
	flags->flags &= ~ HASH_FLAG;
	flags->flags &= ~ MINUS_FLAG;
	flags->flags &= ~ PLUS_FLAG;
	flags->flags &= ~ SPACE_FLAG;
	flags->precision = 0;
	flags->precision_state = NOT_SET;
	flags->width = 0;
	flags->width_state = NOT_SET;
	return (0);
}
