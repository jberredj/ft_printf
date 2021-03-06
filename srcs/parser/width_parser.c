/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:03:28 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/24 00:15:58 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	width_parser(char *str, t_pf *flags)
{
	if (ft_isdigit(*str) == 1)
	{
		flags->width_state = SET;
		flags->width = ft_atoi(str);
		return (ft_intlen(flags->width));
	}
	else if (*str == '*')
	{
		flags->width_state = VAR_VALUE;
		return (1);
	}
	else
	{
		flags->width_state = NOT_SET;
		return (0);
	}
}
