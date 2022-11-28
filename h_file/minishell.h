/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:36:59 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/28 09:58:13 by mvolpi           ###   ########.fr       */
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
	char	*history;
	char	**env;
	char	*exit;
	char	*pipe;
}	t_shell;

/*src*/
int		ft_parse_new_line(t_shell *shell);
int		main(int argc, char **argv, char **envp);
	/*builtins*/
		/*echo*/
int		ft_echo(t_shell *shell);
		/*env_utils*/
int		free_env(char **env);
char	*ft_chrjoin(char *s1, char s2);
void	env(t_shell *shell);
		/*env*/
void	init_shlvl(char	***env, char **envp, int i);
void	get_env(char **envp, char ***env);
int		replece_variable(char **cmd, char *line, t_shell *shell, int i);
void	free_cmd(char **cmd, char *cmd_m);
void	change_env(char **cmd, t_shell *shell);
		/*signal*/
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
