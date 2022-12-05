/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:48:52 by mvolpi            #+#    #+#             */
/*   Updated: 2022/12/05 09:13:32 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

int	ft_echo(t_shell *shell)
{
	int	i;

	i = 4;
	if (shell->input[5] == '-' && shell->input[6] == 'n')
	{
		i = 7;
		while (shell->input[i])
		{
			if (shell->input[++i] == '-' && shell->input[++i] == 'n')
				i++;
			else
				while (shell->input[i])
					printf("%c", shell->input[++i]);
		}
	}
	else
	{
		while (shell->input[++i])
			printf("%c", shell->input[i]);
		printf("\n");
	}
	return (0);
}
