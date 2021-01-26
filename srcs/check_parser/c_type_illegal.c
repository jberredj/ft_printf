/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type_illegal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:21:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/26 16:36:01 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_type_illegal(t_pf *flags)
{
	/*flags->flags &= ~ ZERO_FLAG;*/
	flags->flags &= ~ HASH_FLAG;
	flags->flags &= ~ PLUS_FLAG;
	flags->flags &= ~ SPACE_FLAG;
	flags->precision = 0;
	flags->precision_state = NOT_SET;
	return (0);
}
