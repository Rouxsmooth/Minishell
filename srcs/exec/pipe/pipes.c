/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:04:45 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/10 22:14:07 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	exec_pipe(t_list *icmds, t_icmd *prev, int child)
{
	t_icmd	*icmd;
	t_icmd	*next_icmd;
	pid_t	pid;

	icmd = (t_icmd *)icmds->content;
	next_icmd = NULL;
	if (icmds->next)
		next_icmd = (t_icmd *)icmds->next->content;
	pid = fork();
	if (pid == -1)
		// return idk fork error w/e
	if (pid == 0)
	{
		if (child == 0)
		{
			
		}
	}
}

void	exec_child(t_list *cmds, int nb_cmds, t_data *data)
{
	t_list	*tmp;
	t_cmd	*cmd;
	t_list	*icmds;
	int		child;

	icmds = create_icmds(cmds, nb_cmds);
	tmp = icmds;
	child = -1;
	while (tmp)
	{
		cmd = (t_cmd *) tmp->content;
		exec_pipe(icmds, get_prev(tmp), child);
		child++;
	}
}
