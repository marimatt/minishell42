/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:36:59 by marimatt          #+#    #+#             */
/*   Updated: 2022/11/18 08:56:12 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/h_file/libft.h"

typedef struct s_shell
{
	char	*input;
	char	*split;
}	t_shell;

/*src*/
int	ft_parse_new_line(t_shell *shell);
int	main(void);
	/*builtins*/
		/*echo*/
int	ft_echo(t_shell *shell);

#endif
