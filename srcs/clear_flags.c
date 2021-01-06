/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:59:37 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/06 09:54:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int init_flags(t_pf *flags)
{
	flags->list = NULL;
	flags->printed_char = 0;
	clear_flags(flags);
	return (0);
}

int clear_flags(t_pf *flags)
{
	flags->fd = 1;
	flags->flags = 0;
	flags->length = 0;
	flags->precision = 0;
	flags->precision_state = NOT_SET;
	flags->type = 0;
	flags->width = 0;
	flags->width_state = NOT_SET;
	return (0);
}