/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_up_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:21 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/14 18:26:21 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	up_hex_val(unsigned int num)
{
	unsigned int		rem;
	int					base;

	base = 16;
	if (num / base > 0)
		up_hex_val(num / base);
	rem = num % base;
	if (rem > 9)
		rem += '7';
	else
		rem += '0';
	write(1, &rem, 1);
}

int	ft_pt_up_hex(long long arg)
{
	unsigned int	num;
	int				count;

	num = (unsigned int) arg;
	count = ft_numdig_usign(num, 16);
	up_hex_val(num);
	return (count);
}
