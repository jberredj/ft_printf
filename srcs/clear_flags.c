/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:59:37 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/24 00:07:08 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_flags(t_pf *flags)
{
	flags->ap = NULL;
	ft_bzero(flags->buffer, BUFFER_SIZE);
	flags->buf_count = 0;
	flags->printed_char = 0;
	clear_flags(flags);
	return (0);
}

int	clear_flags(t_pf *flags)
{
	flags->precision = 0;
	flags->precision_state = NOT_SET;
	flags->width = 0;
	flags->width_state = NOT_SET;
	flags->length = 0;
	flags->type = 0;
	flags->fd = 1;
	flags->flags = 0;
	return (0);
}
