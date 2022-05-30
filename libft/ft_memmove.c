/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:52:18 by lemmon            #+#    #+#             */
/*   Updated: 2022/03/19 12:52:18 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			((unsigned char *) dst)[len] = ((unsigned char *) src)[len];
		return (dst);
	}
	else
	{
		while (i++ < len)
		{
			*((unsigned char *) dst) = *((unsigned char *) src);
			dst++;
			src++;
		}
	}
	return (dst - len);
}
