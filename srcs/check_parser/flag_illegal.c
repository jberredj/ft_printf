/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_illegal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:31:42 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:33:43 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_parser.h"

void	flag_illegal(t_pf *flags)
{
	if (flags->flags & MINUS_FLAG)
		flags->flags &= ~ZERO_FLAG;
	if (flags->flags & PLUS_FLAG)
		flags->flags &= ~SPACE_FLAG;
}
