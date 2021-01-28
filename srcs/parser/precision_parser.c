/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:04:16 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 13:27:34 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	precision_parser(char *str, t_pf *flags)
{
	int	len;

	len = 0;
	flags->precision_state = NOT_SET;
	if (*str == '.')
	{
		str++;
		flags->precision_state = SET;
		if (ft_isdigit(*str))
		{
			flags->precision = ft_atoi(str);
			while (ft_isdigit(*str++))
				len++;
			return (len + 1);
		}
		else if (*str == '*')
		{
			flags->precision_state = VAR_VALUE;
			return (2);
		}
		return (1);
	}
	return (0);
}
