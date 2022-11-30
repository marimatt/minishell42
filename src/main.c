/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:02 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/30 09:36:13 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/minishell.h"

int	ft_parse_new_line(t_shell *shell)
{
	int	i;

	i = -1;
	if (ft_strncmp(shell->input, "echo ", 5) == 0)
		ft_echo(shell);
	else if (ft_strncmp(shell->input, "env", 4) == 0)
		env(shell);
	else if (ft_strncmp(shell->input, "exit", 5) == 0)
		exit (write(1, "exit\n", 5));
	else if (ft_strncmp(shell->input, "export", 7) == 0)
		export(shell);
	else if (ft_strncmp(shell->input, "", 2))
		printf("it isn't a shell word\n");
	return (1);
}

int	loop(t_shell *shell)
{
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
		shell->input = readline("minishell: ");
		if (!shell->input)
			return (0 * write(1, "\n", 1));
		if (ft_strncmp(shell->input, "", 1))
			add_history(shell->input);
		ft_parse_new_line(shell);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	(void)envp;
	if (argc > 1)
		exit(write(1, "Error!! There must be only one argument\n", 40));
	g_exit = 0;
	get_env(envp, &shell.env);
	loop(&shell);
	free(shell.input);
	return (0);
}
