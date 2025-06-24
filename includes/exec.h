/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:27:19 by hle-hena          #+#    #+#             */
/*   Updated: 2025/06/23 23:47:59 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <wait.h>

char	*get_path(t_cmd input, t_icmd *cmd);
int		clean_icmds(void);
void	set_exit_val(int ret_val);


int	    is_builtin(t_cmd	*cmd);
int	    ft_cd(char **args, t_data *data);
int	    ft_echo(char **args, t_data *data);
int	    ft_env(char **args, t_data *data);
int	    ft_exit(char **args, t_data *data);
int	    ft_export(char **args, t_data *data);
int	    ft_pwd(char **args, t_data *data);
int	    ft_unset(char **args, t_data *data);
#endif