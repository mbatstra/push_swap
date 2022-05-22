/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numdig_sign.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:25:35 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:08:53 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numdig_sign(int num, int base)
{
	long	arg;
	int		size;

	arg = num;
	size = 1;
	if (arg < 0)
	{
		arg *= -1;
		size++;
	}
	while (arg / base > 0)
	{
		arg /= base;
		size++;
	}
	return (size);
}
