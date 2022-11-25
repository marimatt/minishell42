/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:27:35 by mvolpi            #+#    #+#             */
/*   Updated: 2022/11/25 10:57:51 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

// void	rl_replace_line(const char *text, int clear_undo);

void	handle_sigint(int sig)
{
	(void)sig;
	ft_printf("\n");
	// rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}
