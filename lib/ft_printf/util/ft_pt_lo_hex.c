/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_lo_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:06 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:08:29 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	lo_hex_val(unsigned int num)
{
	unsigned int		rem;
	int					base;

	base = 16;
	if (num / base > 0)
		lo_hex_val(num / base);
	rem = num % base;
	if (rem > 9)
		rem += 'W';
	else
		rem += '0';
	write(1, &rem, 1);
}

int	ft_pt_lo_hex(long long arg)
{
	unsigned int	num;
	int				count;

	num = (unsigned int) arg;
	count = ft_numdig_usign(num, 16);
	lo_hex_val(num);
	return (count);
}
