/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:34:10 by mvolpi            #+#    #+#             */
/*   Updated: 2022/12/01 09:41:08 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

void	add_var(t_shell *shell)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (shell->env[i])
		i++;
	i = i + 1;
	c = 7;
	j = 0;
	while (shell->input[++c])
	{
		shell->env[i][j] = c;
		printf("%c ", shell->env[i][j]);
		j++;
		i++;
	}
}

char	**sort(char **sorting)
{
	int		i;
	int		j;
	int		c;
	char	**sort_env;

	i = 0;
	while (sorting[i])
		++i;
	sort_env = malloc(sizeof(char *) * (i + 1));
	sort_env[i] = NULL;
	i = -1;
	while (sorting[++i])
	{
		j = -1;
		c = 0;
		while (sorting[++j])
			if (ft_strncmp(sorting[i], sorting[j], ft_strlen(sorting[i])) > 0)
				c++;
		sort_env[c] = sorting[i];
	}
	return (sort_env);
}

void	export(t_shell *shell)
{
	char	**sort_env;
	int		i;

	sort_env = NULL;
	if (ft_strncmp(shell->input, "export  ", 8) > 0)
	{
		add_var(shell);
	}	
	else
	{
		sort_env = sort(shell->env);
		i = -1;
		while (sort_env[++i])
			printf("declare -x %s\n", sort_env[i]);
	}
	free(sort_env);
}
