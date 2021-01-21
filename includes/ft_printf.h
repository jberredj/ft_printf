/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:32:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 16:49:06 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "flags_struct.h"
# include "../libft/includes/libft.h"
# include "parser.h"
# include "checker_parser.h"
# include "converter.h"
# define NOT_SET 2
# define SET 1
# define VAR_VALUE 4
# ifndef BONUS
#  define BONUS 0
# endif
int		ft_printf(const char *str, ...);
int		clear_flags(t_pf *flags);
int		init_flags(t_pf *flags);

#endif