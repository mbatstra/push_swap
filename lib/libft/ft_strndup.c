/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:21:40 by mbatstra          #+#    #+#             */
/*   Updated: 2022/04/25 13:21:56 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*dup;

	dup = (char *) malloc(sizeof(char) * size + 1);
	if (!dup)
		return (dup);
	ft_strlcpy(dup, s1, size + 1);
	return (dup);
}
