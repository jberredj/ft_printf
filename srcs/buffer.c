/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:20:24 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/24 00:10:56 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "ft_printf.h"

void	print_buffer(t_pf *flags)
{
	write(flags->fd, flags->buffer, flags->buf_count);
	flags->buf_count = 0;
	ft_bzero(flags->buffer, BUFFER_SIZE);
}

void	add_to_buffer(char *str, int len, t_pf *flags)
{
	int	i;

	i = 0;
	flags->printed_char += len;
	while (i < len)
	{
		flags->buffer[flags->buf_count] = str[i];
		flags->buf_count++;
		if (flags->buf_count == BUFFER_SIZE)
			print_buffer(flags);
		i++;
	}
}
