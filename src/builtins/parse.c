/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:47:29 by mvolpi            #+#    #+#             */
/*   Updated: 2022/12/05 11:15:20 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

int	mod_parse(t_shell *shell, int **l)
{
	if ((shell->cmd[(*l)[3]] == '&'
		&& shell->cmd[(*l)[3] + 1] != '&') || (*l)[5])
		return (0);
	shell->split = ft_stamp_char(shell->split, shell->cmd[(*l)[3]]);
	if (shell->cmd[(*l)[3]] == '>'
		&& shell->cmd[(*l)[3] + 1] == '>')
		shell->split[ft_strlen(shell->split) - 1] += 5 + (0 * (*l)[3]++);
	else if (shell->cmd[(*l)[3]] == '<'
		&& shell->cmd[(*l)[3] + 1] == '<')
		shell->split[ft_strlen(shell->split) - 1] += 5 + (0 * (*l)[3]++);
	else if (shell->cmd[(*l)[3]] == '|'
		&& shell->cmd[(*l)[3] + 1] == '|')
		shell->split[ft_strlen(shell->split) - 1] += '^' + (0 * (*l)[3]++);
	else if (shell->cmd[(*l)[3]] == '&'
		&& shell->cmd[(*l)[3] + 1] == '&')
		shell->split[ft_strlen(shell->split) - 1] += '&' + (0 * (*l)[3]++);
	return (1);
}

int	prnths_parse(t_shell *shell, int **l)
{
	if (shell->cmd[(*l)[3]] == '(')
	{
		if (!(*l)[5])
			shell->split = ft_stamp_char(shell->split, shell->cmd[(*l)[3]]);
		(*l)[5]++;
		(*l)[3]++;
	}
	else if (shell->cmd[(*l)[3]] == ')')
	{
		(*l)[5]--;
		(*l)[3]++;
		if ((*l)[5] > 0)
			return (0);
		return (1);
	}
	return (0);
}

void	parse_loop(t_shell *shell, int **l)
{
	while (++(*l)[2] < (*l)[4])
	{
		(*l)[3]++;
		shell->ls_cmd[(*l)[2]] = ft_strdup("");
		while (shell->cmd[(*l)[3]])
		{
			if (shell->cmd[(*l)[3]] == '\'' && !(*l)[1])
				(*l)[0] = ((*l)[0] + 1) % 2;
			else if (shell->cmd[(*l)[3]] == '"' && !(*l)[0])
				(*l)[1] = ((*l)[1] + 1) % 2;
			else if (!(*l)[0] && !(*l)[1] && mod_parse(shell, l)
				&& ft_strchr("|<>&", shell->cmd[(*l)[3]]))
				break ;
			if (!(*l)[0] && !(*l)[1]
				&& (shell->cmd[(*l)[3]] == '(' || shell->cmd[(*l)[3]] == ')'))
			{
				if (prnths_parse(shell, l))
					(*l)[3] += chr_count(&shell->cmd[(*l)[3]], ' ');
			}
			else
				shell->ls_cmd[(*l)[2]] = ft_stamp_char(shell->ls_cmd[(*l)[2]],
						shell->cmd[(*l)[3]++]);
		}
	}
	shell->ls_cmd[(*l)[2]] = NULL;
}

int	divide_commands(t_shell *shell)
{
	int	arr_a[7];
	int	arr_b[5];
	int	*l;

	shell->split = ft_strdup("");
	arr_a[0] = 0;
	arr_a[1] = 0;
	arr_a[2] = -1;
	arr_a[3] = -1;
	arr_b[0] = 1;
	arr_b[1] = 0;
	arr_b[2] = 0;
	arr_b[3] = -1;
	arr_b[4] = 0;
	arr_a[4] = commands_cont(shell->cmd, &arr_b[0]);
	arr_a[5] = 0;
	shell->trim = 0;
	shell->ls_cmd = NULL;
	shell->ls_cmd = malloc(sizeof(char *) * (arr_a[4] + 1));
	if (!shell->ls_cmd || !shell->split || arr_a[4] == -2)
		return (1);
	l = &arr_a[0];
	parse_loop(shell, &(l));
	return (focus_pipe(shell, 0));
}

int	ft_parse(t_shell *shell)
{
	if (divide_commands(shell))
		return (finish_loop(shell, 2));
}
