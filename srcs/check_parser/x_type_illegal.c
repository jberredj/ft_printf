/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:31:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 14:31:15 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int x_type_illegal(t_pf_flags *flags)
{
	flags->flags &= ~PLUS_FLAG;
	flags->flags &= ~SPACE_FLAG;
	return (0);
}