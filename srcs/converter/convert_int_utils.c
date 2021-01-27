/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:10:26 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 12:15:27 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "parser.h"

char	*zero_precision(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;

	tmp = NULL;
	if (flags->precision_state == SET)
	{
		if (flags->precision == 0 && *len == 1 && str[0] == '0')
		{
			tmp = ft_calloc(1, sizeof(char));
			if (!tmp)
				return (NULL);
			tmp[0] = '\0';
			*len -= 1;
			free(str);
			str = tmp;
		}
		else
			tmp = str;
	}
	else
		tmp = str;
	return (tmp);
}

char	*nbr_precision(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;
	int		precision;

	if (str == NULL)
		return (NULL);
	str = zero_precision(str, len, flags);
	if (flags->precision_state == NOT_SET || flags->precision <= *(int *)len)
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
		else if (flags->flags & SPACE_FLAG)
			*tmp = ' ';
		ft_strlcpy(&tmp[1], str, *len + 1);
		*len += 1;
		free(str);
	}
	else
		tmp = str;
	return (tmp);
}

int	zero_flag(int sign, t_pf *flags)
{	
	if (flags->flags & ZERO_FLAG)
	{
		if (flags->flags & MINUS_FLAG && flags->precision_state == NOT_SET)
			return (0);
		if (flags->flags & (SPACE_FLAG | PLUS_FLAG))
			sign = 1;
		if (flags->precision_state & NOT_SET)
		{
			flags->precision = flags->width - sign;
			flags->width_state = NOT_SET;
			flags->precision_state = SET;
			if(flags->flags & HASH_FLAG)
				return (1);
		}
	}
	return (0);
}

int	unbr_size(unsigned long long *unbr, t_pf *flags)
{
	va_list	*ap;

	ap = flags->ap;
	if (flags->length != 0)
	{
		if (flags->length & H_LENGTH)
			*unbr = (t_uintmax)((unsigned short)(va_arg(*ap, unsigned int)));
		else if (flags->length & HH_LENGTH)
			*unbr = (t_uintmax)((unsigned char)(va_arg(*ap, unsigned int)));
		else if (flags->length & L_LENGTH)
			*unbr = (t_uintmax)(va_arg(*ap, unsigned long));
		else if (flags->length & LL_LENGTH)
			*unbr = (va_arg(*ap, unsigned long long));
	}
	else
		*unbr = (t_uintmax)va_arg(*ap, unsigned int);
	return (0);
}
