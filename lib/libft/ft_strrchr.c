/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:44:49 by fatkeski          #+#    #+#             */
/*   Updated: 2024/11/26 07:22:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return (&(((char *)s)[len]));
		len--;
	}
	return (0);
}
