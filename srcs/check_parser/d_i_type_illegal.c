/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_type_illegal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:28:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 14:10:23 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

void	d_i_type_illegal(t_pf *flags)
{
	flags->flags &= ~HASH_FLAG;
	if (flags->precision_state != NOT_SET)
		flags->flags &= ~ZERO_FLAG;
}
