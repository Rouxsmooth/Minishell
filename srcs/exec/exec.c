/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:30:06 by meroux            #+#    #+#             */
/*   Updated: 2025/07/07 17:03:11 by mzaian           ###   ########.fr       */
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

void	exec_one(t_list *cmds, t_data *data)
{
	if (is_builtin(cmds->content))
		return (exec_builtin(cmds->content, data));
}

void	exec_pipe(t_cmd *cmd, t_list *icmds)
{
	t_icmd	*icmd;

	icmd = (t_icmd *)icmds->content;
	if (index_cmd == 0)
	if (!icmd->open)
	{
		dup2(icmd->pipe[1], ((t_icmd *)icmds->next->content)->pipe[0]);
	}
}

void	open_in(t_icmd *icmd, t_open *curr_open)
{
	if (access(curr_open->str, F_OK | R_OK) == -1)
		//ft_perror clear data exit
	if (curr_open->mode == 2)
	{
		close(icmd->pipe[0]);
		open(curr_open->str, O_RDONLY, 0777);
		return ;
	}
	close(icmd->pipe[0]);
	//open() heredoc?
}

void	open_out(t_icmd *icmd, t_open *curr_open)
{
	if (access(curr_open->str, F_OK | W_OK) == -1)
		//ft_perror clear data exit
	if (!curr_open->mode)
	{
		close(icmd->pipe[1]);
		open(curr_open->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		return ;
	}
	close(icmd->pipe[1]);
	open(curr_open->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return ;
}

void	get_opens(t_list *open_list, t_icmd *icmd)
{
	t_open	*current_open;

	while (open_list)
	{
		current_open = (t_open *)open_list->content;
		if (!dir_exists(current_open->str))
			//ft_perror clear data exit
		if (current_open->mode == 0 || current_open->mode == 1)
			open_out(icmd, current_open->mode);
		else if (current_open->mode == 2 || current_open->mode == 3)
			open_in(icmd, current_open->mode);
		open_list = open_list->next;
	}
	return ;
}

void	create_pipes(t_list *icmds, t_list *cmds)
{
	t_list	*tmp_icmds;
	t_list	*tmp_cmds;
	t_icmd	*icmd;
	t_cmd	*cmd;
	int		pipe_success;

	tmp_icmds = icmds;
	tmp_cmds = cmds;
	while (tmp_icmds)
	{
		icmd = (t_icmd *)tmp_icmds->content;
		cmd = (t_cmd *)tmp_cmds->content;
		pipe_success = pipe(icmd->pipe);
		if (pipe_success < 0)
			//ft_perror clear data exit
		get_opens(cmd->open, icmd);
		tmp_icmds = tmp_icmds->next;
		tmp_cmds = tmp_cmds->next;
	}
	return ;
}

t_list	*create_icmds(t_list *cmds, int nb_cmds)
{
	t_cmd	*cmd;
	t_icmd	*icmd;
	t_list	*head;
	t_list	*icmds;
	t_list	*tmp;

	tmp = cmds->next;
	head = (t_list *)malloc(sizeof(t_list));
	icmd = (t_icmd *)icmds->content;
	cmd = (t_cmd *)tmp->content;
	icmd->args = cmd->args;
	icmds = head->next;
	while (tmp && nb_cmds != 1)
	{
		icmds = (t_list *)malloc(sizeof(t_list));
		icmd = (t_icmd *)icmds->content;
		cmd = (t_cmd *)tmp->content;
		icmd->args = cmd->args;
		icmds = icmds->next;
		tmp = tmp->next;
	}
	icmds = head;
	return (create_pipes(icmds, cmds), icmds);
}

void	exec_child(t_list *cmds, t_data *data)
{
	t_list	*tmp;
	t_cmd	*cmd;
	t_list	*icmds;
	//int		child;

	icmds = create_icmds(cmds, ft_lstsize(cmds));
	tmp = cmds;
	//child = 0;
	while (tmp)
	{
		cmd = (t_cmd *) tmp->content;
			exec_pipe(cmd, fds);
	}
}

void	executing(t_list *cmds, t_data *data)
{
	int nb_cmds;

	// in this AST, if a list size is longer than 1, it has a pipe and the first pipe result needs to be cast in the second 
	nb_cmds = ft_lstsize(cmds);
	if (nb_cmds == 1)
		return (exec_one(cmds, data));
	return (exec_child(cmds, nb_cmds, data));
}

