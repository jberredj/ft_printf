/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:31:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:34:18 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_parser.h"

void	x_type_illegal(t_pf *flags)
{
	flags->flags &= ~PLUS_FLAG;
	flags->flags &= ~SPACE_FLAG;
}
