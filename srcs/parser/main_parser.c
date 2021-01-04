/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:09:45 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/04 19:24:05 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf_parser.h"

char	*main_parser(char *str, t_pf_flags *flags)
{
	int	flags_check;
	int	width_check;
	int	precision_check;
	int	length_check;
	int	type_check;

	flags_check = 1;
	while (flags_check == 1)
	{
		flags_check = flag_parser(str, flags);
		str += flags_check;
	}
	width_check = width_parser(str, flags);
	str += width_check;
	precision_check = precision_parser(str, flags);
	str += precision_check;
	length_check = length_parser(str, flags);
	str += length_check;
	type_check = type_parser(str, flags);
	str += type_check;
	return (str);
}
