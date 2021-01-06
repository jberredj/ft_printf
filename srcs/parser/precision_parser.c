/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:04:16 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 17:54:04 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf_parser.h"
#include "libft.h"

int	precision_parser(char *str, t_pf *flags)
{
	flags->precision_state = NOT_SET;
	if (*str == '.')
	{
		str++;
		if (ft_isdigit(*str) == 1)
		{
			flags->precision_state = SET;
			flags->precision = ft_atoi(str);
			return (ft_intlen(flags->precision) + 1);
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