/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:30:06 by meroux            #+#    #+#             */
/*   Updated: 2025/06/23 23:45:24 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*find_executable(char *cmd, t_list *env)
{
	t_list		*tmp_env;

	tmp_env = env;
	while (tmp_env->next)
	{
		if (!access(tmp_env->content, X_OK))
			;
		else if (!ft_strncmp(cmd, (char *)tmp_env->content,
			ft_max(ft_strlen(cmd), ft_strlen((char *)tmp_env->content))))
				return (ft_strdup(cmd));
		tmp_env = tmp_env->next;
	}
	return (NULL);
}

void	exec_external(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	char	*path;

	path = find_executable(cmd->args[0], data->env);
	if (!path)
	{
		printf("minishell: %s: command not found\n", cmd->args[0]);
		exit(127);
	}
	pid = fork();
	if (!pid)
	{
		execve(path, cmd->args, (char **)data->env);
		perror("execve failed");
		exit(1);
	}
	else
		waitpid(pid, NULL, 0);
	return (free(path));
}

void	exec_builtin(t_cmd *cmd, t_data *data)
{
	pid_t pid;

	pid = fork();
	if (!pid)
	{
		if (!ft_strncmp(cmd->args[0], "cd", 2))
			ft_cd(cmd->args, data);
		else if (!ft_strncmp(cmd->args[0], "echo", 4))
			ft_echo(cmd->args, data);
		else if (!ft_strncmp(cmd->args[0], "env", 3))
			ft_env(cmd->args, data);
		else if (!ft_strncmp(cmd->args[0], "exit", 4))
			ft_exit(cmd->args, data);
		else if (!ft_strncmp(cmd->args[0], "export", 7))
			ft_export(cmd->args, data);
		else if (!ft_strncmp(cmd->args[0], "pwd", 3))
			ft_pwd(cmd->args, data);
		else if (!ft_strncmp(cmd->args[0], "unset", 5))
			ft_unset(cmd->args, data);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
	return ;
}

void	exec_one(t_list *cmds, t_data *data)
{
	if (is_builtin(cmds->content))
		return (exec_builtin(cmds->content, data));
}

void	exec_child(t_list *cmds, int nb_cmds, t_data *data);

void	executing(t_list *cmds, t_data *data)
{
	int nb_cmds;

	nb_cmds = ft_lstsize(cmds);
	if (nb_cmds == 1)
		return (exec_one(cmds, data));
	return (exec_child(cmds, nb_cmds, data));
}
