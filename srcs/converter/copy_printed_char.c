/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_printed_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:08:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:40:50 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_struct.h"

void	copy_printed_char(t_pf *flags)
{
	int	*n;

	n = va_arg(*(flags->ap), int *);
	*n = flags->printed_char;
}
