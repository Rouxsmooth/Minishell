/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:50:49 by hle-hena          #+#    #+#             */
/*   Updated: 2025/06/24 00:12:21 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_getenv(const char *str)
{
	int		size;
	char	*line;
	t_list	*env;

	size = ft_strlen(str);
	env = data()->env;
	while (env)
	{
		line = ft_strnstr(env->content, str, size);
		if (line && line[size] == '=')
		{
			if (line[size + 1])
				return (line + size + 1);
			return ("");
		}
		env = env->next;
	}
	return (NULL);
}
