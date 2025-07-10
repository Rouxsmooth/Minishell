/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:04:45 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/08 20:04:46 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	exec_pipe(t_cmd *cmd, t_list *icmds, int child)
{
	t_icmd	*icmd;

	icmd = (t_icmd *)icmds->content;
	if (child == 0)
	if (!icmd->open)
	{
		dup2(icmd->pipe[1], ((t_icmd *)icmds->next->content)->pipe[0]);
	}
}
