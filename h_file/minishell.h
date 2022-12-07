/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:36:59 by marimatt          #+#    #+#             */
/*   Updated: 2022/12/05 11:29:52 by mvolpi           ###   ########.fr       */
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

int	g_exit;

typedef struct s_shell
{
	char	*input;
	char	*word;
	char	**env;
	char	*exit;
	char	*pipe;
	char	*cmd;
	char	*sort;
	char	*split;
	char	**ls_cmd;
	int		trim;
	int		l;
}	t_shell;

/*src*/
int		ft_parse_new_line(t_shell *shell);
int		main(int argc, char **argv, char **envp);
	/*builtins*/
		/*echo*/
int		ft_echo(t_shell *shell);
		/*env*/
int		free_env(char **env);
void	init_shlvl(char	***env, char **envp, int i);
void	get_env(char **envp, char ***env);
void	env(t_shell *shell);
		/*export*/
char	**sort(char **sorting);
void	export(t_shell *shell);
		/*signal*/
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
