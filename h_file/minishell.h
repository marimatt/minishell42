/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:36:59 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/24 09:28:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/h_file/libft.h"

typedef struct s_shell
{
	char	*input;
	char	*split;
	char	*history;
}	t_shell;

/*src*/
int		ft_parse_new_line(t_shell *shell);
int		main(int argc, char **argv);
	/*builtins*/
		/*echo*/
int		ft_echo(t_shell *shell);
		/*signal*/
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
