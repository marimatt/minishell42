/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:56:09 by mvolpi            #+#    #+#             */
/*   Updated: 2022/12/05 09:13:39 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

int	free_env(char **env)
{
	int	i;

	i = -1;
	if (!env)
		return (1);
	while (env[++i])
		free(env[i]);
	free(env);
	return (0);
}

void	init_shlvl(char	***env, char **envp, int i)
{
	char	*shlvl;

	shlvl = ft_itoa(ft_atoi(&envp[i][6]) + 1);
	(*env)[i] = ft_strjoin("SHLVL=", shlvl);
	free(shlvl);
}

void	get_env(char **envp, char ***env)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	*env = malloc(sizeof(char *) * (i + 1));
	i = -1;
	if (!(*env))
		exit(write(1, "There is an error allocating env!!\n", 35));
	while (envp[++i])
	{
		if (!ft_strncmp("SHLVL=", envp[i], 6))
			init_shlvl(env, envp, i);
		else if (!ft_strncmp("SHELL=", envp[i], 6))
			(*env)[i] = ft_strdup("SHELL=minishell");
		else
		{
			(*env)[i] = ft_strdup(envp[i]);
			if ((*env)[i])
				continue ;
			free_env((*env));
			exit(write(1, "There is an error setting up env\n", 32));
		}
	}
	(*env)[i] = 0;
}

void	env(t_shell *shell)
{
	int	i;
	int	j;
	int	b;

	i = -1;
	while (shell->env[++i])
	{
		b = 1;
		j = -1;
		while (shell->env[i][++j])
		{
			if (ft_strncmp(&shell->env[i][j], "=", 1) == 0)
				b = 0;
		}
		if (b == 0)
			printf("%s\n", shell->env[i]);
	}
	free(shell->exit);
	shell->exit = ft_strdup("0");
}
