/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:21:14 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 17:55:04 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	print_int(t_pf flags)
{
	int len;

	len = ft_intlen(*(int *)(flags.data));
	if (flags.flags & MINUS_FLAG)
		printf("MINUS_FLAG SET\n");
	if (flags.flags & PLUS_FLAG)
		printf("PLUS_FLAG SET\n");
	if (flags.flags & SPACE_FLAG)
		printf("SPACE_FLAG SET\n");
	if (flags.flags & ZERO_FLAG)
		printf("ZERO_FLAG SET\n");
	if (flags.flags & HASH_FLAG)
		printf("HASH_FLAG SET\n");
	printf("width = %d\n", flags.width);
	ft_putnbr_fd(*(int *)(flags.data), flags.fd);
}
