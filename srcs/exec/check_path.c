/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:49:18 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/10 20:50:19 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	check_path(char *path)
{
	struct stat	s;

	if (access(path, F_OK) == -1)
		//print no such file or directory
	if (access(path, X_OK) == -1)
		//print permission denied
	if (stat(path, &s) == 0 && S_ISDIR(s.st_mode))
		//print is a directory
		
	return (1);
}

char	**get_splitted_path(void)
{
	char	*fullpath;
	char	*split_path;

	fullpath = ft_getenv("PATH");
	if (!fullpath)
		//idk yet
	fullpath = ft_substr(fullpath, 4, ft_strlen(fullpath) - 5);
	split_path = ft_split(fullpath, ':');
	free(fullpath);
	return (split_path);
}

int	get_splitpath_len(void)
{
	int		i;
	int		colons;
	char	*env_path;

	env_path = ft_getenv("PATH");
	if (!env_path)
		return (0);
	if (!*env_path)
		return (0);
	i = 0;
	colons = 1;
	while (env_path[i])
	{
		if (env_path[i] == ':')
			colons++;
		i++;
	}
	return (colons);
}

char	*find_executable_path(char *cmd)
{
	char	*split_path;
	char	*commandpath;
	int		i;

	split_path = get_splitted_path();
	i = 0;
	while (split_path[i])
	{
		commandpath = ft_strjoin(split_path[i++], cmd);
		if (access(commandpath, F_OK) == 0)
		{
			if (check_path(commandpath) == 1)
				return (ft_free_tab((char **)split_path,
						get_splitpath_len()), commandpath);
		}
		free(commandpath);
	}
	return (NULL); //cmd not found
}

char	*find_executable(char *cmd)
{
	if (ft_strchr(cmd, '/'))
		return (check_path(cmd));
	return (find_executable_path(ft_strjoin("/", cmd)));
}
