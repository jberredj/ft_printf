/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:09:45 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 15:25:13 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*main_parser(char *str, t_pf *flags)
{
	char	*str_store;
	int		flags_check;

	str_store = str;
	str++;
	flags_check = 1;
	while (flags_check == 1)
	{
		flags_check = flag_parser(str, flags);
		str += flags_check;
	}
	str += width_parser(str, flags);
	str += precision_parser(str, flags);
	str += length_parser(str, flags);
	str += type_parser(str, flags);
	if ((str - 1) == str_store || flags->type == 0)
		return (str_store);
	return (str);
}
