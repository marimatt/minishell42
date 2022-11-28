/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:21:50 by mvolpi            #+#    #+#             */
/*   Updated: 2022/11/28 09:55:10 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

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

	i = -1;
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

int	replece_variable(char **cmd, char *line, t_shell *shell, int i)
{
	int	j;
	int	x;

	j = -1;
	while (ft_isalnum(line[i]))
		i++;
	if (line[1] == '?' && i--)
	{
		while (shell->exit[++j])
			*cmd = ft_chrjoin(*cmd, shell->exit[j]);
		return (1);
	}
	while (shell->env[++j])
	{
		if (!ft_strncmp(shell->env[j], &line[1], i - 1)
			&& shell->env[j][i - 1] == '=')
		{
			x = 0;
			while (shell->env[j][i - 1 + ++x])
				*cmd = ft_chrjoin(*cmd, shell->env[j][i - 1 + x]);
			break ;
		}
	}
	return (i - 1);
}

void	free_cmd(char **cmd, char *cmd_m)
{
	free(*cmd);
	*cmd = ft_strdup(cmd_m);
	free(cmd_m);
}

void	change_env(char **cmd, t_shell *shell)
{
	char	*cmd_m;
	int		i;
	int		a[2];

	i = -1;
	a[0] = 0;
	a[1] = 0;
	cmd_m = malloc(sizeof(char) * 2);
	if (!cmd_m)
		return ;
	ft_bzero(cmd_m, 2);
	while ((*cmd)[++i])
	{
		if ((*cmd)[i] == '\'' && !a[1])
			a[0] = (a[0] + 1) % 2;
		if ((*cmd)[i] == '\"')
			a[1] = (a[1] + 1) % 2;
		if ((*cmd)[i] == '$' && !a[0])
			i += replece_variable(&cmd_m, &(*cmd)[i], shell, 1);
		else
			cmd_m = ft_chrjoin(cmd_m, (*cmd)[i]);
	}
	free_cmd(cmd, cmd_m);
}
