/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:02 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/24 09:24:17 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/minishell.h"

int	ft_parse_new_line(t_shell *shell)
{
	int	i;

	i = -1;
	if (ft_strncmp(shell->input, "echo ", 5) == 0)
		ft_echo(shell);
	else if (ft_strncmp(shell->input, "exit", 5) == 0)
		exit (0);
	return (1);
}

void	handle_sigint(int sig)
{
	(void)sig;
	ft_printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}

int	main(int argc, char **argv)
{
	t_shell	shell;

	if (argc > 1)
	{
		printf("Error!! There must be only one argument");
		exit (0);
		printf("%s", argv[1]);
	}
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
		shell.input = readline("minishell: ");
		if (!shell.input)
			return (0 * write(1, "\n", 1));
		if (ft_strncmp(shell.input, "", 1))
			add_history(shell.input);
		ft_parse_new_line(&shell);
	}
	free(shell.input);
	return (0);
}
