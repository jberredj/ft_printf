/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:38:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 16:06:48 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "buffer.h"

char	*nbr_precision(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;
	int		precision;

	if (str == NULL)
		return (NULL);
	if (flags->precision_state == NOT_SET || flags->precision <= (int)*len)
		return (str);
	precision = flags->precision - *len;
	tmp = ft_calloc(flags->precision + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, '0', precision);
	ft_strlcpy(&tmp[precision], str, *len + 1);
	*len += precision;
	free(str);
	return (tmp);
}

char	*nbr_sign(char *str, int sign, size_t *len, t_pf *flags)
{
	char	*tmp;	

	if (str == NULL)
		return (NULL);
	if (sign == 1 || flags->flags & (PLUS_FLAG | SPACE_FLAG))
	{
		tmp = ft_calloc(*len + 2, sizeof(char));
		if (!tmp)
			return (NULL);
		if (sign == 1)
			*tmp = '-';
		else if (flags->flags & PLUS_FLAG)
			*tmp = '+';
		else if (flags->flags & PLUS_FLAG)
			*tmp = ' ';
		ft_strlcpy(&tmp[1], str, *len + 1);
		*len += 1;
		free(str);
	}
	else
		tmp = str;
	return (tmp);
}

char	*process_width(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;
	int		width;

	if (str == NULL)
		return (NULL);
	if (flags->width_state == NOT_SET || flags->width == 0)
		return (str);
	width = flags->width;
	tmp = ft_calloc(width + *len + 1, sizeof(char));
		if (!tmp)
			return (NULL);
	if (flags->flags & MINUS_FLAG)
	{
		ft_strlcpy(tmp, str, *len + 1);
		ft_memset(&tmp[*len], ' ', width);
	}
	else
	{
		ft_memset(tmp, ' ', width);
		ft_strlcpy(&tmp[width], str, *len + 1);
	}
	free(str);
	*len += flags->width;
	return (tmp);
}

void	zero_flag(int sign, t_pf *flags)
{
	
	if (flags->flags & ZERO_FLAG)
	{
		if (flags->flags & (SPACE_FLAG | PLUS_FLAG))
			sign = 1;
		flags->precision = flags->width - sign;
		flags->width_state = NOT_SET;
		flags->precision_state = SET;
	}
}

int convert_int(t_pf *flags)
{
	char	*str;
	int		nbr;
	int		sign;
	size_t	len;

	sign = 0;
	nbr = va_arg(*(flags->ap), int);
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	zero_flag(sign, flags);
	str = nbr_precision(str, &len, flags);
	str = nbr_sign(str, sign, &len, flags);
	flags->width -= len;
	str = process_width(str, &len, flags);
	add_to_buffer(str, len, flags);
	return (0);
}