/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_printed_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:08:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 13:19:34 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	copy_printed_char(t_pf *flags)
{
	int	*n;

	n = va_arg(*(flags->ap), int *);
	*n = flags->printed_char;
}
