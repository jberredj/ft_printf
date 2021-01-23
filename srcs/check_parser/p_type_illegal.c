/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:26:04 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/24 00:14:51 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int	p_type_illegal(t_pf *flags)
{
	flags->flags &= ~ ZERO_FLAG;
	flags->flags &= ~ HASH_FLAG;
	flags->flags &= ~ PLUS_FLAG;
	flags->flags &= ~ SPACE_FLAG;
	flags->precision = 0;
	flags->precision_state = NOT_SET;
	return (0);
}
