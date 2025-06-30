/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:04:27 by mzaian            #+#    #+#             */
/*   Updated: 2025/06/24 18:28:49 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_echo(char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = 0;
	if (!args[1])
		return (printf("\n"), 0);
	if (ft_strncmp(args[1], "-n", ft_max(ft_strlen(args[1]), 2)))
	{
		nl = 1;
		i++;
	}
	while (args[i])
		printf("%s", args[i++]);
	if (nl)
		printf("\n");
	return (0);
}
