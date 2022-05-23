/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:24 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/14 18:27:20 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lookup(int opcode, long long arg)
{
	static t_func	arr[7] = {
		&ft_pt_dec,
		&ft_pt_udec,
		&ft_pt_str,
		&ft_pt_chr,
		&ft_pt_ptr,
		&ft_pt_lo_hex,
		&ft_pt_up_hex,
	};

	return (arr[opcode](arg));
}

static int	get_opcode(char type)
{
	if (type == 'd' || type == 'i')
		return (0);
	else if (type == 'u')
		return (1);
	else if (type == 's')
		return (2);
	else if (type == 'c')
		return (3);
	else if (type == 'p')
		return (4);
	else if (type == 'x')
		return (5);
	else if (type == 'X')
		return (6);
	else
		return (-1);
}

static int	pt_value(long long arg, char type)
{
	int	count;

	count = 1;
	if (type == '%')
		write(1, "%", 1);
	else if (get_opcode(type) == -1)
		return (0);
	else
		count = lookup(get_opcode(type), arg);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	long long	arg;
	va_list		arg_ptr;
	int			count;

	count = 0;
	va_start(arg_ptr, fmt);
	while (*fmt)
	{
		while (fmt[0] == '%' && fmt[1])
		{
			if (fmt[1] != '%')
				arg = va_arg(arg_ptr, long long);
			count += pt_value(arg, fmt[1]);
			fmt += 2;
		}
		if (!*fmt)
			break ;
		write(1, fmt, 1);
		count++;
		fmt++;
	}
	va_end(arg_ptr);
	return (count);
}
