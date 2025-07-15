/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:50:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/15 11:47:59 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	open_in(t_icmd *icmd, t_open *curr_open)
{
	if (access(curr_open->str, F_OK | R_OK) == -1)
		//ft_perror clear data exit
	if (curr_open->mode == 2)
	{
		close(icmd->pipe[0]);
		icmd->pipe[0] = open(curr_open->str, O_RDONLY, 0777);
		return ;
	}
	close(icmd->pipe[0]);
	//open() heredoc?
}

void	open_out(t_icmd *icmd, t_open *curr_open)
{
	if (access(curr_open->str, F_OK | W_OK) == -1)
		//ft_perror clear data exit
	if (!curr_open->modez)
	{
		close(icmd->pipe[1]);
		icmd->pipe[1] = open(curr_open->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		return ;
	}
	close(icmd->pipe[1]);
	icmd->pipe[1] = open(curr_open->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
