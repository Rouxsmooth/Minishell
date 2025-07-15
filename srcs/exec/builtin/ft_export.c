/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:03:32 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/15 11:59:59 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

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
	while (tmp_env)
	{
		printf("declare -x %s\n", (char *)tmp_env->content);
		tmp_env = tmp_env->next;
	}
	return (0);
}
