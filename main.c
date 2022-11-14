/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:02 by marimatt          #+#    #+#             */
/*   Updated: 2022/06/20 14:37:50 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// int ft_parse_new_line(char *line)
// {
// 	words = ft_split(line, " ");
// 	if (words[0] == "echo")
// 		ft_echo(words);
// 	else if
// 	{
// 		continue;
// 	}
// 	return 1;
// }


int	main()
{
	char	*line;

	while (1)
	{
		printf("%s", "rootMarco@1293123: ");
		line = readline(NULL);
		// ft_parse_new_line(line);
	}
	free(line);
	return (0);
}
