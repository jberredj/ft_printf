/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:09:09 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 09:57:42 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H
# include "ft_printf.h"
int	copy_printed_char(t_pf *flags);
int	print_precision(t_pf *flags);
int	print_width(t_pf *flags);
int	print_hex(t_pf *flags);
int	print_int(t_pf *flags);

#endif