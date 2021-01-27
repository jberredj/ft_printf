/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:44:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 13:31:55 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "buffer.h"
#include "ft_printf.h"

int	convert_char(t_pf *flags)
{
	char	*str;
	size_t	len;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (-1);
	str[1] = '\0';
	if (flags->type & PERCENT_TYPE)
		str[0] = '%';
	else
		str[0] = (char)va_arg(*(flags->ap), int);
	len = 1;
	flags->width -= len;
	if (flags->flags & ZERO_FLAG)
		str = process_width(str, &len, '0', flags);
	else
		str = process_width(str, &len, ' ', flags);
	if (str == NULL)
		return (-1);
	add_to_buffer(str, len, flags);
	free(str);
	return (0);
}
