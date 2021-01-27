/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:08:51 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 15:05:19 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "flags_struct.h"
# include "parser_flag.h"
# include "parser_length.h"
# include "parser_type.h"
# include "../libft/includes/ft_to.h"
# define NOT_SET 2
# define SET 1
# define VAR_VALUE 4

char	*main_parser(char *str, t_pf *flags);
int		flag_parser(char *str, t_pf *flags);
int		width_parser(char *str, t_pf *flags);
int		precision_parser(char *str, t_pf *flags);
int		length_parser(char *str, t_pf *flags);
int		type_parser(char *str, t_pf *flags);
#endif
