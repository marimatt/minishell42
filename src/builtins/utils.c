/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:12:55 by mvolpi            #+#    #+#             */
/*   Updated: 2022/12/05 11:14:24 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/minishell.h"

int	chr_count(char *cmd, char c)
{
	int	i;

	i = -1;
	while (cmd[++i])
		if (!(cmd[i] == c))
			break ;
	return (i);
}

char	ft_stamp_char(char *s1, char s2)
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
