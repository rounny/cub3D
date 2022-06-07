/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:52:48 by lemmon            #+#    #+#             */
/*   Updated: 2022/06/06 14:15:21 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *) mem)[i] = '\0';
		++i;
	}
	return (mem);
}

void	*ft_calloc_int(size_t count, int sym)
{
	size_t	i;
	int		*mem;

	i = 0;
	mem = malloc(count * sizeof(int));
	if (!mem)
		return (NULL);
	while (i < count)
	{
		mem[i] = sym;
		++i;
	}
	return (mem);
}
