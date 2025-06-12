/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroux <meroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:30:06 by meroux            #+#    #+#             */
/*   Updated: 2025/06/12 06:52:17 by meroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	exec_builtin(t_cmd *cmd, t_data *data)
{
	
}

void	exec_one(t_list *cmds, t_data *data)
{
	if (is_builtin(cmds->content))
		return (exec_builtin(cmds->content, data));
}

void	executing(t_list *cmds, t_data *data)
{
	int nb_cmds;

	nb_cmds = ft_lstsize(cmds);
	if (nb_cmds == 1)
		return (exec_one(cmds, data));
	return (exec_child(cmds, nb_cmds, data));
}
