/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:53:27 by lemmon            #+#    #+#             */
/*   Updated: 2022/03/19 12:53:27 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	j = ft_strlen(dst);
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size + i < dstsize - 1 && dstsize > 0)
	{
		while (j < dstsize - 1 && src[i])
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (dst_size > dstsize)
		dst_size = dstsize;
	return (dst_size + src_size);
}
