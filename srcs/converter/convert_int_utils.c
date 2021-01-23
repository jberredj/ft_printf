/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:10:26 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/23 23:33:07 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "parser.h"

char	*nbr_precision(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;
	int		precision;

	if (str == NULL)
		return (NULL);
	if (flags->precision_state == SET && flags->precision == 0 
		&& *len == 1 && str[0] == '0')
		{
			str[0] = ' ';
			return (str);
		}
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

void	zero_flag(int sign, t_pf *flags)
{
	
	if (flags->flags & ZERO_FLAG)
	{
		if (flags->flags & (SPACE_FLAG | PLUS_FLAG))
			sign = 1;
		if (flags->precision_state & NOT_SET)
		{
			flags->precision = flags->width - sign;
			flags->width_state = NOT_SET;
			flags->precision_state = SET;
		}
	}
}