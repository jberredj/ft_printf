/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:32:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 13:48:09 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "flags_struct.h"
# include "ft_pf_parser.h"
# include "parser_flag.h"
# include "parser_length.h"
# include "parser_type.h"
# include "checker_parser.h"
# define NOT_SET 2
# define SET 1
# define VAR_VALUE 4
# ifndef BONUS
#  define BONUS 1
# endif
int		ft_printf(const char *str, ...);
int		clear_flags(t_pf *flags);
int		init_flags(t_pf *flags);
int		print_int(t_pf *flags);
int print_width(t_pf *flags);

#endif