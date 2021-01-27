/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:38:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:43:41 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "parser.h"
#include "buffer.h"

int	nbr_size(long long *nbr, t_pf *flags)
{
	int		sign;
	va_list	*ap;

	sign = 0;
	ap = flags->ap;
	if (flags->length != 0)
	{
		if (flags->length & H_LENGTH)
			*nbr = (long long)((short)(va_arg(*ap, int)));
		else if (flags->length & HH_LENGTH)
			*nbr = (long long)((char)(va_arg(*ap, int)));
		else if (flags->length & L_LENGTH)
			*nbr = (long long)(va_arg(*ap, long));
		else if (flags->length & LL_LENGTH)
			*nbr = (va_arg(*ap, long long));
	}
	else
		*nbr = (long long)va_arg(*ap, int);
	if (*nbr < 0)
	{
		sign = 1;
		*nbr = -*nbr;
	}
	return (sign);
}

int	convert_int(t_pf *flags)
{
	char		*str;
	long long	nbr;
	int			sign;
	size_t		len;

	nbr = 0;
	sign = nbr_size(&nbr, flags);
	str = ft_lltoa(nbr);
	len = ft_strlen(str);
	zero_flag(sign, flags);
	str = nbr_precision(str, &len, flags);
	str = nbr_sign(str, sign, &len, flags);
	flags->width -= len;
	str = process_width(str, &len, ' ', flags);
	if (str == NULL)
		return (-1);
	add_to_buffer(str, len, flags);
	free(str);
	return (0);
}

int	convert_uint(t_pf *flags)
{
	char				*str;
	unsigned long long	unbr;
	size_t				len;

	unbr = 0;
	unbr_size(&unbr, flags);
	str = ft_ulltoa(unbr);
	len = ft_strlen(str);
	zero_flag(0, flags);
	str = nbr_precision(str, &len, flags);
	flags->width -= len;
	str = process_width(str, &len, ' ', flags);
	if (str == NULL)
		return (-1);
	add_to_buffer(str, len, flags);
	free(str);
	return (0);
}
