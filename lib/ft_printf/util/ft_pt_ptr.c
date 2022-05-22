/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:10 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:08:26 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ptr_val(unsigned long num)
{
	unsigned long	rem;
	int				base;

	base = 16;
	if (num / base > 0)
		ptr_val(num / base);
	rem = num % base;
	if (rem > 9)
		rem += 'W';
	else
		rem += '0';
	write(1, &rem, 1);
}

int	ft_pt_ptr(long long arg)
{
	unsigned long	adr;
	int				count;

	write(1, "0x", 2);
	count = 2;
	adr = (unsigned long) arg;
	count += ft_numdig_ptr(adr, 16);
	ptr_val(adr);
	return (count);
}
