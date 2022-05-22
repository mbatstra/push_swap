/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pt_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:14 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/14 18:26:15 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pt_str(long long arg)
{
	char	*str;
	int		count;

	count = 0;
	str = (char *) arg;
	if (!str)
	{
		write(1, "(null)", 6);
		count = 6;
		return (count);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
