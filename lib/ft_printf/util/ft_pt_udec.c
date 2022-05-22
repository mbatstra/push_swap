/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_udec.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:17 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/14 18:26:18 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	udec_val(unsigned int num)
{
	unsigned int	rem;
	int				base;

	base = 10;
	if (num / base > 0)
		udec_val(num / base);
	rem = num % base + '0';
	write(1, &rem, 1);
}

int	ft_pt_udec(long long arg)
{
	unsigned int	num;
	int				count;

	num = (unsigned int) arg;
	count = ft_numdig_usign(num, 10);
	udec_val(num);
	return (count);
}
