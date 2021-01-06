/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:05:05 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 17:54:28 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pf_parser.h"
#include "parser_length.h"

int	length_parser(char *str, t_pf *flags)
{
	if (*str == 'h')
		flags->length |= H_LENGTH;
	if ((flags->length & H_LENGTH) && *(str + 1) == 'h')
	{
		flags->length |= HH_LENGTH;
		flags->length ^= H_LENGTH;
	}
	if (*str == 'l')
		flags->length |= L_LENGTH;
	if ((flags->length & L_LENGTH) && *(str + 1) == 'l')
	{
		flags->length |= LL_LENGTH;
		flags->length ^= L_LENGTH;
	}
	if ((flags->length & HH_LENGTH) || (flags->length & LL_LENGTH))
		return (2);
	if (flags->length != 0)
		return (1);
	return (0);
}
