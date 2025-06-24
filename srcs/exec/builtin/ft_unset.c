/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:15:53 by mzaian            #+#    #+#             */
/*   Updated: 2025/06/24 18:02:32 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_unset(char **args, t_list *env)
{
	t_list	*tmp;
	int		i;

	i = 1;
	while (args[i])
	{
		tmp = ft_getenv_struct(args[i], NULL);
		if (!tmp)
			// return alloc error
		ft_realloc(tmp, ft_strlen(args[i]));
		tmp = args[i];
		// refresh env ?  refresh prompt ?
		i++;
	}
	return (0);
}
