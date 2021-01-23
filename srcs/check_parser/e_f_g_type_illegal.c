/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_f_g_type_illegal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:27:11 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/24 00:14:25 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "checker_parser.h"

int	e_f_g_type_illegal(t_pf *flags)
{
	flags->length &= ~ LL_LENGTH;
	flags->length &= ~ H_LENGTH;
	flags->length &= ~ HH_LENGTH;
	return (0);
}
