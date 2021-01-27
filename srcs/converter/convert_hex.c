/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:46:56 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 14:11:54 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "buffer.h"
#include "ft_printf.h"
#include "parser_type.h"

static char	*base_selector(t_pf *flags)
{
	if (flags->type & UPPER_TYPE)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

char		*hash_flag(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;

	if (flags->flags & HASH_FLAG)
	{
		tmp = (char *)ft_calloc(*len + 3, sizeof(char));
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '0';
		if (flags->type & UPPER_TYPE)
			tmp[1] = 'X';
		else
			tmp[1] = 'x';
		ft_strlcpy(&tmp[2], str, *len + 2);
		*len += 2;
		free(str);
	}
	else
		tmp = str;
	return (tmp);
}

int			convert_hex(t_pf *flags, int point)
{
	size_t				len;
	char				*base;
	char				*str;
	unsigned long long	unbr;

	unbr = 0;
	base = base_selector(flags);
	unbr_size(&unbr, flags);
	str = ft_ulltoa_base(unbr, base);
	len = ft_strlen(str);
	if (zero_flag(0, flags) && unbr != 0)
		flags->precision -= 2;
	str = nbr_precision(str, &len, flags);
	if (point == 1 || unbr != 0)
		str = hash_flag(str, &len, flags);
	flags->width -= len;
	str = process_width(str, &len, ' ', flags);
	if (str == NULL)
		return (-1);
	add_to_buffer(str, len, flags);
	free(str);
	return (0);
}
