/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:02 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/17 11:03:50 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/minishell.h"

// int	ft_echo(char *words)
// {
// 	printf("%c", words[0]);
// 	return (0);
// }

// int	ft_parse_new_line(char *line)
// {
// 	char	*words;
// 	int		i;

// 	i = 0;
// 	words = NULL;
// 	while (*line)
// 	{
// 		words[i] = **ft_split(line, ' ');
// 		i++;
// 	}
// 	printf("%c\n", words[0]);
// 	// while (*line)
// 	// {
// 	// 	words[i] = line[i];
// 	// 	if (ft_strncmp(&words[0], "echo", 5) == 0)
// 	// 		ft_echo(words);
// 	// }
// 	return (1);
// }

int	main()
{
	char	*line;

	while (1)
	{
		// printf("%s", "rootMarco@1293123: ");
		line = readline("minishell: ");
		// ft_parse_new_line(line);
	}
	free(line);
	return (0);
}
