/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_sign_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:05:48 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/20 09:41:08 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putnbr_sign_fd(int n, int fd, int print_sign)
{
	unsigned int	us_n;

	if (n < 0)
	{
		if (print_sign == 1)
			ft_putchar_fd('-', fd);
		us_n = (unsigned int)n;
		us_n = -us_n;
	}
	else
		us_n = (unsigned int)(n);
	if (us_n >= 10)
	{
		ft_putnbr_fd(us_n / 10, fd);
	}
	ft_putchar_fd((char)(us_n % 10 + '0'), fd);
}
