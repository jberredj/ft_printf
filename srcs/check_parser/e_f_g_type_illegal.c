/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_f_g_type_illegal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:27:11 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:33:33 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_parser.h"

void	e_f_g_type_illegal(t_pf *flags)
{
	flags->length &= ~LL_LENGTH;
	flags->length &= ~H_LENGTH;
	flags->length &= ~HH_LENGTH;
}
