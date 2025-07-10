/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:54:01 by mzaian            #+#    #+#             */
/*   Updated: 2025/07/10 20:51:55 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "mini.h"

void	open_in(t_icmd *icmd, t_open *curr_open);
void	open_out(t_icmd *icmd, t_open *curr_open);
void	get_opens(t_list *open_list, t_icmd *icmd);

#endif