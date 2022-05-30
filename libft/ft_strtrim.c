/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:54:15 by lemmon            #+#    #+#             */
/*   Updated: 2022/03/19 12:54:15 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int			start;
	int			i;
	int			end;
	char		*out;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && (end > start))
		end--;
	out = (char *)malloc(end - start + 2);
	if (!out)
		return (NULL);
	while (start <= end)
		out[i++] = s1[start++];
	out[i] = '\0';
	return (out);
}
