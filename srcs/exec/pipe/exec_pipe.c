/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:04:45 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/24 15:51:20 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	exec_pipe(t_cmd *cmd, t_list *icmds, int child)
{
	t_icmd	*icmd;

	icmd = (t_icmd *)icmds->content;
	if (child == 0)
	{
		dup2(icmd->pipe[1], 1);
		execve(icmd->path, icmd->args, (char **)data()->env);
	}
}
