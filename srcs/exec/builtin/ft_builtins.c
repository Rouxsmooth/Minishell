/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:12:57 by meroux            #+#    #+#             */
/*   Updated: 2025/06/24 18:08:33 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_builtin(t_cmd	*cmd)
{
	int			cmd_len;
	int			i;
	static char	*builtin_cmds[7] = {"echo", "cd", "pwd", "export", "unset",
			"env", "exit"};

	cmd_len = ft_strlen(cmd->args[0]);
	i = -1;
	while (++i < 7)
	{
		if (ft_strncmp(cmd->args[0], builtin_cmds[i], ft_min(cmd_len,
					ft_strlen(builtin_cmds[i]))) == 0)
			return (1);
	}
	return (0);
}

