/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numdig_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:25:21 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:09:01 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numdig_ptr(unsigned long num, int base)
{
	int	size;

	size = 1;
	while (num / base > 0)
	{
		num /= base;
		size++;
	}
	return (size);
}
