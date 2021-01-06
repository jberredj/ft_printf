/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:25:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 17:54:12 by jberredj         ###   ########.fr       */
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
	flags->length &= ~LL_LENGTH;
	flags->length &= ~H_LENGTH;
	flags->length &= ~HH_LENGTH;
	return (0);
}