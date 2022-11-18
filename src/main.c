/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:02 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/18 08:44:36 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/minishell.h"

int	ft_echo(t_shell *shell)
{
	int	i;

	i = 4;
	if (shell->input[5] == '-' && shell->input[6] == 'n')
	{
		i = 7;
		while (shell->input[++i])
			printf("%c", shell->input[i]);
	}
	else
	{
		while (shell->input[++i])
			printf("%c", shell->input[i]);
		printf("\n");
	}
	return (0);
}

int	ft_parse_new_line(t_shell *shell)
{
	int	i;

	i = -1;
	if (ft_strncmp(shell->input, "echo ", 5) == 0)
		ft_echo(shell);
	return (1);
}

int	main()
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
