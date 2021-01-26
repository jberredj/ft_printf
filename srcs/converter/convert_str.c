/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:16:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/26 16:18:51 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "buffer.h"
#include "ft_printf.h"

static char	*get_string(size_t *len, t_pf *flags)
{
	char	*str;

	str = (char *)va_arg(*(flags->ap), char *);
	if (str != NULL)
	{
		*len = ft_strlen(str);
		str = ft_substr(str, 0, *len);
	}
	else 
	{
		*len = 6;
		str = ft_substr("(null)", 0, *len);
	}
	return (str);
}

int convert_str(t_pf *flags)
{
	char	*str;
	size_t	len;

	len = 0;
	str = get_string(&len, flags);
	if (str == NULL)
		return (-1);
	if (flags->precision_state == SET && flags->precision < (int)len)
	{
		str[flags->precision] = '\0';
		len = flags->precision;
	}
	flags->width -= len;
	str = process_width(str, &len, flags);
	if (str == NULL)
		return (-1);
	add_to_buffer(str, len, flags);
	free(str);
	return (0);
}
