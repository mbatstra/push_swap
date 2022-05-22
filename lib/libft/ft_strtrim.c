/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:22:06 by mbatstra          #+#    #+#             */
/*   Updated: 2022/04/25 13:22:09 by mbatstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new_len;
	size_t	ret_value;
	char	*new_str;

	while (is_inset(*s1, set))
		s1++;
	new_len = ft_strlen(s1);
	if (!new_len)
	{
		new_str = ft_calloc(1, 1);
		return (new_str);
	}
	while (is_inset(s1[new_len - 1], set))
		new_len--;
	new_str = (char *) malloc((new_len + 1) * sizeof(char));
	if (!new_str)
		return (new_str);
	ret_value = ft_strlcpy(new_str, s1, new_len + 1);
	return (new_str);
}
