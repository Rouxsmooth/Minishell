/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:30:06 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/10 20:52:59 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	exec_external(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	char	*path;

	path = find_executable(cmd->args[0]);
	if (!path)
	{
		//cmd not found
		exit(127); // test exit codes btw
	}
	execve(path, &cmd->args[1], (char **)data->env);
	return (free(path));
}

void	exec_one(t_cmd *cmd, t_data *data)
{
	if (is_builtin(cmd))
		return (exec_builtin(cmd, data));
	exec_external(cmd, data);
	return ;
}

void	executing(t_list *cmds, t_data *data)
{
	int nb_cmds;

	nb_cmds = ft_lstsize(cmds);
	if (nb_cmds == 1)
		return (exec_one(cmds, data));
	return (exec_child(cmds, nb_cmds, data));
}

