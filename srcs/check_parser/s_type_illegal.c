/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:25:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 14:33:40 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int s_type_illegal(t_pf *flags)
{
	flags->flags &= ~ZERO_FLAG;
	flags->flags &= ~HASH_FLAG;
	flags->flags &= ~PLUS_FLAG;
	flags->flags &= ~SPACE_FLAG;
	return (0);
}