/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_printed_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:08:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 17:08:27 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int copy_printed_char(t_pf *flags)
{
	int *n;

	n = va_arg(*(flags->list), int *);
	*n = flags->printed_char;
	return (0);
}