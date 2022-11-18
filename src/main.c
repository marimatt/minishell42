/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:02 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/18 08:56:18 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/minishell.h"

int	ft_parse_new_line(t_shell *shell)
{
	int	i;

	i = -1;
	if (ft_strncmp(shell->input, "echo ", 5) == 0)
		ft_echo(shell);
	return (1);
}

int	main(void)
{
	t_shell	shell;

	while (1)
	{
		shell.input = readline("minishell: ");
		ft_parse_new_line(&shell);
	}
	free(shell.input);
	return (0);
}
