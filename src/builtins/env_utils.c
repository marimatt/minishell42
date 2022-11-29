/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:35:44 by mvolpi            #+#    #+#             */
/*   Updated: 2022/11/29 09:20:26 by mvolpi           ###   ########.fr       */
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

char	*ft_chrjoin(char *s1, char s2)
{
	size_t	i;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	str[i++] = s2;
	str[ft_strlen(s1) + 1] = '\0';
	free(s1);
	return (str);
}

void	env(t_shell *shell)
{
	int		i;

	i = -1;
	shell->env[1] = ("SHELL=minishell");
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
	free(shell->exit);
	shell->exit = ft_strdup("0");
}
