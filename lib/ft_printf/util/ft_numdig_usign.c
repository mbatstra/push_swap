/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numdig_usign.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:25:43 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:09:06 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numdig_usign(unsigned long num, int base)
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
