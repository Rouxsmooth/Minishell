/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:12:57 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/10 20:58:16 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_builtin(t_cmd *cmd)
{
	int			cmd_len;
	int			i;
	char	**builtin_cmds;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (0);
	builtin_cmds = (char *[7]){"echo", "cd", "pwd", "export", "unset", "env",
		"exit"};
	cmd_len = ft_strlen(cmd->args[0]);
	i = -1;
	while (++i < 7)
	{
		if (ft_strncmp(cmd->args[0], builtin_cmds[i], ft_max(cmd_len,
					ft_strlen(builtin_cmds[i]))) == 0)
			return (1);
	}
	return (0);
}

void	exec_builtin(t_cmd *cmd, t_data *data)
{
	if (!ft_strncmp(cmd->args[0], "cd", 2))
		ft_cd(cmd->args);
	else if (!ft_strncmp(cmd->args[0], "echo", 4))
		ft_echo(cmd->args);
	else if (!ft_strncmp(cmd->args[0], "env", 3))
		ft_env(cmd->args, data->env);
	else if (!ft_strncmp(cmd->args[0], "exit", 4))
		ft_exit(cmd->args, data);
	else if (!ft_strncmp(cmd->args[0], "export", 7))
		ft_export(cmd->args, data->env);
	else if (!ft_strncmp(cmd->args[0], "pwd", 3))
		ft_pwd(cmd->args);
	else if (!ft_strncmp(cmd->args[0], "unset", 5))
		ft_unset(cmd->args);
	return ;
}
