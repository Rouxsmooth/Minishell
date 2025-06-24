/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:05:55 by mzaian            #+#    #+#             */
/*   Updated: 2025/06/24 18:06:59 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_cd(char **args, t_list *env)
{
	t_list		*tmp;
	struct stat	s;

	if (args[1])
		// return too many args error
	if (stat(args[0], &s) != 0)
		// return stat error
	if (!S_ISDIR(s.st_mode))
		// return not directory error
	tmp = ft_getenv_struct("PWD", NULL);
    if (!tmp)
        // return alloc error
    ft_realloc(tmp, ft_strlen(args[1]));
    tmp = args[1];    
    // refresh env ?  refresh prompt ?
	return (1);
}
