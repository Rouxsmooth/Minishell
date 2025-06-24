/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 06:12:57 by meroux            #+#    #+#             */
/*   Updated: 2025/06/24 01:21:49 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_cd(char **args, t_list *env)
{
	t_list		*tmp_env;
	struct stat	s;

	if (args[1])
		// return too many args error
	if (stat(args[0], &s) != 0)
		// return stat error
	if (!S_ISDIR(s.st_mode))
		// return not directory error
	tmp_env = env;
	while (tmp_env->next)
	{
		if (ft_strncmp((char *)tmp_env->content, "PWD",
				ft_max(3, ft_strlen((char *)tmp_env->content))) == 0)
		{
			tmp_env->content = args[0];
			// refresh env ?  refresh prompt ?
			return (0);
		}
	}
	return (1);
}
int	ft_echo(char **args, t_data *data)
{
	return (0);
}
int	ft_env(char **args, t_list *env)
{
	t_list *tmp_env;

	tmp_env = env;
	while (tmp_env->next)
	{
		printf("%s\n", (char *)tmp_env->content);
		tmp_env = tmp_env->next;
	}
	return (0);
}
int	ft_exit(char **args, t_data *data)
{
	return (0);
}

t_list	*sort_lst_by_str(t_list *list, int size)
{
	int		i;
	t_list	*current;
	void	*temp;

	i = 0;
	while (i < size - 1)
	{
		current = list;
		while (current && current->next)
		{
			if (ft_strncmp((char *)current->content,
				(char *)current->next->content, ft_max(
						ft_strlen((char *)current->content),
						ft_strlen((char *)current->next->content))) > 0)
			{
				temp = current->content;
				current->content = current->next->content;
				current->next->content = temp;
			}
			current = current->next;
		}
		i++;
	}
	return (list);
}

int	ft_export(char **args, t_list *env)
{
	t_list *tmp_env;
	int		size;

	tmp_env = env;
	if (!tmp_env)
		return;
	if (size < 2)
		return (printf("declare -x %s\n", (char *)tmp_env->content), 0);
	size = ft_lstsize(tmp_env);
	sort_lst_by_str(tmp_env, size);
	while (tmp_env->next)
	{
		printf("declare -x %s\n", (char *)tmp_env->content);
		tmp_env = tmp_env->next;
	}
	return (0);
}
int	ft_pwd(char **args)
{
	char	*pwd;

	pwd = ft_getenv("PWD");
	if (pwd)
		return (printf("%s\n", pwd));
	return (0);
}
int	ft_unset(char **args, t_data *data)
{
	return (0);
}

int	is_builtin(t_cmd	*cmd)
{
	int			cmd_len;
	int			i;
	static char	*builtin_cmds[7] = {"echo", "cd", "pwd", "export", "unset",
			"env", "exit"};

	cmd_len = ft_strlen(cmd->args[0]);
	i = -1;
	while (++i < 7)
	{
		if (ft_strncmp(cmd->args[0], builtin_cmds[i], ft_min(cmd_len,
					ft_strlen(builtin_cmds[i]))) == 0)
			return (1);
	}
	return (0);
}

