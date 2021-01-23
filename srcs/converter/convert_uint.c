/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:38:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/23 14:12:55 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "buffer.h"

int	unbr_size(unsigned long long *unbr, t_pf *flags)
{
	if (flags->length != 0)
	{
		if (flags->length & H_LENGTH)
			*unbr = (t_uintmax)((short)(va_arg(*(flags->ap), unsigned int)));
		else if (flags->length & HH_LENGTH)
			*unbr = (t_uintmax)((char)(va_arg(*(flags->ap), unsigned int)));
		else if (flags->length & L_LENGTH)
			*unbr = (t_uintmax)(va_arg(*(flags->ap), unsigned long));
		else if (flags->length & LL_LENGTH)
			*unbr = (va_arg(*(flags->ap), unsigned long long));
	}
	else 
		*unbr = (t_uintmax)va_arg(*(flags->ap), unsigned int);

	return (0);
}	

int convert_uint(t_pf *flags)
{
	char	*str;
	unsigned long long		unbr;
	int		sign;
	size_t	len;

	unbr = 0;
	str = NULL;
	sign = unbr_size(&unbr, flags);
	/*str = ft_ulltoa(unbr);*/
	len = ft_strlen(str);
	zero_flag(sign, flags);
	/*str = nbr_precision(str, &len, flags);*/
	flags->width -= len;
	/*str = process_width(str, &len, flags);*/
	add_to_buffer(str, len, flags);
	if (str == NULL)
		return (-1);
	free(str);
	return (0);
}