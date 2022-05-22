/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbatstra <mbatstra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:26:29 by mbatstra      #+#    #+#                 */
/*   Updated: 2021/12/14 18:26:30 by mbatstra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef int	(*t_func)(long long);
int	ft_printf(const char *fmt, ...);
int	ft_pt_udec(long long arg);
int	ft_pt_dec(long long arg);
int	ft_pt_str(long long arg);
int	ft_pt_chr(long long arg);
int	ft_pt_ptr(long long arg);
int	ft_pt_lo_hex(long long arg);
int	ft_pt_up_hex(long long arg);
int	ft_numdig_sign(int num, int base);
int	ft_numdig_usign(unsigned long num, int base);
int	ft_numdig_ptr(unsigned long num, int base);

#endif
