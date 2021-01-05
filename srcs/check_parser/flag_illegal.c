/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_illegal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:31:42 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 14:31:56 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int flag_illegal(t_pf_flags *flags)
{
	if (flags->flags & MINUS_FLAG)
		flags->flags &= ~ZERO_FLAG;
	if (flags->flags & PLUS_FLAG)
		flags->flags &= ~SPACE_FLAG;
	return (0);
}