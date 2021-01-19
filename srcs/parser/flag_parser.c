/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:02:46 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 14:11:05 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf_parser.h"
#include "parser_flag.h"

int	flag_parser(char *str, t_pf *flags)
{
	if (*str == '-')
		flags->flags |= MINUS_FLAG | FOUND;
	if (*str == '0')
		flags->flags |= ZERO_FLAG | FOUND;
	if (BONUS == 1)
	{
		if (*str == '+')
			flags->flags |= PLUS_FLAG | FOUND;
		if (*str == ' ')
			flags->flags |= SPACE_FLAG | FOUND;
		if (*str == '#')
			flags->flags |= HASH_FLAG | FOUND;
	}
	if (flags->flags & FOUND)
	{
		flags->flags ^= FOUND;
		return (1);
	}
	return (0);
}