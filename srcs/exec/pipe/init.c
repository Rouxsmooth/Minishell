/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:52:18 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/15 11:55:31 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

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
		if (tmp_cmds->next != cmds)
			ft_lstadd_front(&((t_cmd *)tmp_cmds->next->content)->open,
			ft_lstnew(icmd->pipe[1]));
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
	create_pipes(icmds, cmds);
	return (icmds);
}
