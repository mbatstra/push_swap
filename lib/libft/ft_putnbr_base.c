/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:19:56 by mbatstra          #+#    #+#             */
/*   Updated: 2022/04/25 13:19:57 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long i, int base, int set_prefix, int hex_cap)
{
	long	num;
	long	rem;

	num = i;
	if (num < 0)
	{
		if (base != 16)
			ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (base == 16 && set_prefix && !hex_cap)
		ft_putstr_fd("0x", 1);
	else if (base == 16 && set_prefix && hex_cap)
		ft_putstr_fd("0X", 1);
	else if (base == 8 && set_prefix)
		ft_putstr_fd("0", 1);
	if (num / base > 0)
		ft_putnbr_base(num / base, base, 0, hex_cap);
	rem = num % base;
	if (rem > 9 && hex_cap)
		ft_putchar_fd(rem + '7', 1);
	else if (rem > 9 && !hex_cap)
		ft_putchar_fd(rem + 'W', 1);
	else
		ft_putchar_fd(rem + '0', 1);
}
