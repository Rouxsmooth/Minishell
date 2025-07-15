/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:14:50 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/15 11:59:53 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_env(char **args, t_list *env)
{
	t_list *tmp_env;

	if (args[1])
		// return too many args error
	tmp_env = env;
	while (tmp_env)
	{
		printf("%s\n", (char *)tmp_env->content);
		tmp_env = tmp_env->next;
	}
	return (0);
}
