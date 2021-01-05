/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:22:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 14:32:06 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PARSER_H
# define CHECKER_PARSER_H
#include "flags_struct.h"
int check_parser(t_pf_flags *flags);
int c_type_illegal(t_pf_flags *flags);
int s_type_illegal(t_pf_flags *flags);
int p_type_illegal(t_pf_flags *flags);
int e_f_g_type_illegal(t_pf_flags *flags);
int d_i_type_illegal(t_pf_flags *flags);
int u_type_illegal(t_pf_flags *flags);
int n_type_illegal(t_pf_flags *flags);
int x_type_illegal(t_pf_flags *flags);
int flag_illegal(t_pf_flags *flags);

#endif