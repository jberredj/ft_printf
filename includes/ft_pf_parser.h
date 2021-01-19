/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:08:51 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 14:34:08 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PF_PARSER_H
# define FT_PF_PARSER_H
# include "ft_printf.h"
# include "parser_type.h"
# include "parser_flag.h"
char	*main_parser(char *str, t_pf *flags);
int		width_parser(char *str, t_pf *flags);
int		type_parser(char *str, t_pf *flags);
int		precision_parser(char *str, t_pf *flags);
int		flag_parser(char *str, t_pf *flags);

# endif