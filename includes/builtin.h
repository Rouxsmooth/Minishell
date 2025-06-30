/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:28:07 by mzaian            #+#    #+#             */
/*   Updated: 2025/06/30 14:24:28 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <sys/stat.h>

int	ft_cd(char **args);
int	ft_echo(char **args);
int	ft_env(char **args, t_list *env);
int	ft_exit(char **args, t_data *data);
int	ft_export(char **args, t_list *env);
int	ft_pwd(char **args);
int	ft_unset(char **args);

#endif