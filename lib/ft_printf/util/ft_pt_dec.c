/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_dec.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:01 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:08:35 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	dec_val(int num)
{
	long	arg;
	long	rem;
	int		base;

	base = 10;
	arg = num;
	if (arg < 0)
	{
		write(1, "-", 1);
		arg *= -1;
	}
	if (arg / base > 0)
		dec_val(arg / base);
	rem = arg % base + '0';
	write(1, &rem, 1);
}

int	ft_pt_dec(long long arg)
{
	long	num;
	int		count;

	num = (long) arg;
	count = ft_numdig_sign(num, 10);
	dec_val(num);
	return (count);
}
