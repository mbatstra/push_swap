/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_chr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:25:51 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/16 20:08:39 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pt_chr(long long arg)
{
	char	c;

	c = (char) arg;
	write(1, &c, 1);
	return (1);
}
