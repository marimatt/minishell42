/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:16:03 by mvolpi            #+#    #+#             */
/*   Updated: 2022/12/05 11:30:08 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

int	finish_loop(t_shell *shell, int index)
{
	int	i;

	if (index == 2)
		shell->pipe = ft_strdup("");
	free(shell->cmd);
	free_cmd(shell->ls_cmd);
	if (!shell->pipe)
	{
		free(shell->split);
		return (1);
	}
	i = 0;
	while (shell->split[i] == '&')
		i++;
	if (i > 0 && shell->split[i] == 0)
		printf("%s\n", shell->pipe);
	if (index == 1 && !(shell->split[shell->trim - 1] == '&'
			&& !((shell->trim - 1) > 0
				&& ft_strchr("(<>AC", shell->split[shell->trim - 2]))))
		printf("%s\n", shell->pipe);
	if (!shell->l)
		free(shell->pipe);
	free(shell->split);
	return (0);
}
