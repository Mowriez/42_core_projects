/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:07:27 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/06 09:37:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//LIBRARIES-------------------------------------------------------------

# include "../libs/lib42.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>

// COLOR_MACROS----------------------------------------------------------------

# define RED "\033[3;31m"
# define YEL "\033[1;33m"
# define BLU "\033[0;34m"
# define RES "\033[0m"

// PIPES-----------------------------------------------------------------------

# define READ 0
# define WRITE 1

// TOKEN TYPES-----------------------------------------------------------------

# define STRING 1
# define DIV 2
# define PIPE 3
# define I_REDIR 4
# define O_REDIR 5
# define APPEND_REDIR 6
# define H_DOC 7

// GLOBAL VARIABLE-------------------------------------------------------------

extern int	g_exit;

// MAIN STRUCT ----------------------------------------------------------------

typedef struct s_ms {
	char			**og_env;
	struct s_env	*env_ll;
	char			*rl_input;
	char			ms_cwd[1024];
	char			*new_path;
	char			*old_path;
	struct s_cmd	*cmd_ll;
}	t_ms;

// LEXER NODES STRUCT ---------------------------------------------------------

typedef struct s_token {
	char			*value;
	int				type;
	struct s_token	*next;
}	t_token;

// PARSER OUTPUT NODE STRUCT --------------------------------------------------

typedef struct s_cmd {
	char			*cmd;
	char			**cmd_arr;
	int				num;
	int				input_fd;
	int				output_fd;
	t_ms			*ms_struct;
	struct s_cmd	*next;
}	t_cmd;

// ENV NODE STRUCT ------------------------------------------------------------

typedef struct s_env {
	char			*string;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// HELPER STRUCT RUN COMMANDS -------------------------------------------------

typedef struct s_run {
	int			pid;
	int			next_fds[2];
	int			prev_fds[2];
	int			waitpid_status;
}	t_run;

// HELPER STRUCT PATH ARRAY ---------------------------------------------------

typedef struct s_paths {
	t_env		*tk;
	char		**paths;
	char		*tmp;
	int			j;
	int			k;
}	t_paths;

//FUNCTION PROTOTYPES----------------------------------------------------------

//MAIN-------------------------------------------------------------------------

// minishell.c

// main_run_fcts.c
int		run_shell(t_ms *ms_struct);
int		input_prompt(t_ms *ms_struct);

// clean_up_1.c
void	free_env_ll(t_env *env_copy);
void	free_cmd_ll(t_cmd *head);
void	free_double_arr(char **arr);
void	clean_up_run(t_ms *ms_struct);
void	reset_ms_struct(t_ms *ms_struct);

// clean_up_2.c
void	free_ms_struct(t_ms *data);
int		free_in_check_rl_input(char *rl_input);
void	free_token_ll(t_token *head);

//PARSING----------------------------------------------------------------------

// env_init.c
void	init_env_list(t_ms *ms_struct, char **envp);
t_env	*make_new_node(char *str);
void	add_env_node_end(t_env **head, t_env *new_node);
char	**init_env_arr(t_env *env_head);

// env_utils.c
char	**ft_split_env(char *str);
int		len_substr_env(char *str, int start, char end_char);

// int_main.c
void	interpreter(t_token **token_ll, t_ms *ms_struct);
void	init_cmd_node(t_ms *ms_struct, t_cmd *cmd_node, t_token **token, \
							int cmd_num);
int		count_str_nbr(t_token *token);
t_cmd	*new_cmd_node(void);

//int_redir.c
int		input_redir(int *input_fd, char *infile);
int		output_redir(int *output_fd, char *outfile);
int		append_redir(int *output_fd, char *outfile);

// int_utils_1.c
t_token	*iterate_lex_ll(t_cmd *cmd_node, t_token **token, int *n);
t_token	*interpret_string(t_cmd *cmd, t_token **token_list, int *cntr);
t_token	*interpret_div(t_cmd *cmd, t_token **token_ll, int *cntr);
t_token	*interpret_redir(t_token **token_ll, t_cmd *cmd);
char	*strjoin_cmd_arr(char *target, char *addition);

// int_utils_2.c
void	set_cmd_path(t_cmd *cmd);
char	**get_possible_paths(t_cmd *cmd);
char	**append_slash(char **paths);
int		check_for_builtin(char *cmd_string);
char	*strjoin_paths(char *target, char *addition);

// int_utils_3.c
int		no_path(char **paths, t_cmd *cmd);
int		functioning_path(t_cmd *cmd);

// lex_check_input_1.c
void	check_args(int argc, char **argv);
int		check_rl_input(t_ms *ms_struct);
int		check_quotes(char *input);
int		check_empty_prompt(char *input);
int		check_special_chars(char *input);

// lex_check_input_2.c
int		lex_err_msg(char *description);
int		check_empty_pipes(char *rl_input);
int		skip_char(char *input, char c);
int		check_redirs(char *input);
int		check_single(char *s, int *i, int which);

// lex_check_input_3.c
int		check_double(char *s, int *i, int which);
int		skip_spaces(char *input);

// lex_expand_input_1.c
char	*expand_input(t_ms *ms_struct);
char	*resize_expanded_str(t_ms *ms_struct, int *i, char *exp_str);
char	*crop_whitespaces(char *rl_input);
char	*ret_env_value(t_ms *ms_struct, char *str, int i);
char	*ret_exit_status(void);

// lex_expand_input_2.c
char	*get_new_ret(char *exp_str, char *env_value, int *i);
char	*ret_str_start(char *exp_str, int i);
char	*ret_str_end(char *exp_str, int i);
char	*ret_env_key(char *str, int i);
char	*find_env_value(t_ms *ms_struct, char *key);

// lex_expand_input_3.c
char	*extract_value(char *env_str);
char	*cut_var(char *str, int i);

// lex_main.c
void	lexer(char *exp_str, t_token **token_head);
t_token	*tokenize_quotes(char *exp_str, int *i, char quote_type);
t_token	*tokenize_string(char *exp_str, int *i);
t_token	*tokenize_divider(char *exp_str, int *i);
t_token	*tokenize_redir_single(char *exp_str, int *i, char redir_type);

// lex_utils_1.c
t_token	*tokenize_redir_double(char *exp_str, int *i, char redir_type);
t_token	*tokenize_pipe(int *i);
void	add_token_to_end(t_token **token_head, t_token *new_node);
int		len_w_o_quotes(char *exp_str, char quote_type);
int		len_str_token(char *exp_str);

// lex_utils_2.c
int		len_redir_token(char *exp_str);
int		len_spaces(char *exp_str);

// par_main.c
int		parser(t_ms *ms_struct);
t_ms	*init_ms_struct(char **envp);

// visualize_helpers.c
void	print_env_ll(t_env *head);
void	print_token_ll(t_token *head);
char	*translate_type(int type);
void	print_cmd_ll(t_cmd *head);

//BUILTINS---------------------------------------------------------------------

// builtin_cd.c
char	*get_env_val(t_env *env_ll, char *key, int key_size);
void	builtin_cd(t_ms *data, char **args);
void	reset_env_directory_entries(t_ms *data);
int		check_update_env_2(t_ms *data, char *str_var, char *key, int k_size);

// builtin_echo.c
int		builtin_echo(char **args);

// builtin_env.c
void	output_env_ll(t_ms *data);
void	increment_shlvl(t_ms *data);
void	update_shlvl(t_ms *data);

// builtin_exit.c
int		is_number(char *str);
void	builtin_exit(t_cmd *data);

// builtin_export.c
void	print_export_no_args(t_ms *data);
void	add_var_env_ll(t_ms *data, char *str_var);
int		check_update_env(t_ms *data, char *str_var, char *key, int k_size);
void	builtin_export(t_ms *data, char **args);
void	check_valid_var(char *key, int key_sz, t_ms *data, char *arg);
int		check_no_args(t_ms *data, char **args);

// buitlin_pwd.c
int		builtin_pwd(t_ms *data);

// builtin_unset.c
void	free_node(t_env *node);
int		is_valid_var_name(char *key);
void	delete_var_env(t_ms *data, char *key);
void	builtin_unset(t_ms *data, char **args);

// builtins_exe.c
int		is_builtins(t_cmd *cmnd);
int		check_execute(t_cmd *cmnd, char *cmd_name, int cmd_len,
			void (*builtin_func)(t_ms*, char**));
int		builtin_parent_only(t_cmd *cmnd);
int		builtin_runable_child(t_cmd *cmnd);

// builtins_exe_2.c
int		export_helper(t_cmd *cmnd);
int		ft_isnum(char *str);

//EXECUTION--------------------------------------------------------------------

// exe_cmds.cd
void	wait_children(int pid, int *waitpid_status);
void	exe_child_proccess(int pid, int *prev_pipe_fds,
			int *next_pipe_fds, t_cmd *cmnd);
void	launch_child_handle_redir(int pid, int *prev_pipe_fds,
			int *next_pipe_fds, t_cmd *cmnd);
void	run_commands(t_cmd *cmnd);

// exe_heredoc.c
void	heredoc_child_signal(void);
void	heredoc_parent_signal(void);
void	heredoc_child_process(int *pipe_fd, char *delimiter_str);
int		heredoc_parent_process(pid_t pid, int *pipe_fd);
int		ft_heredoc(t_cmd *cmnd, char *delmiter_str);

// exe_redir.c
void	redir_child_io(int *prev_pipe_fds, int *next_pipe_fds,
			t_cmd *cmnd, int prev_cmnd_exists);
void	redir_parent_io(int *prev_pipe_fds, int *next_pipe_fds,
			t_cmd *cmnd);
int		setup_pipe_builtin(t_cmd *cmnd, int *prev_pipe_fds,
			int *next_pipe_fds, int redirect_needed);

// exe_utils.c
int		failed_fork(int pid);
void	ft_exit_status(char *str, int exit_code, char *cmd);
int		ft_strerror_status(int exit_status, char *cmd);
char	**copy_mod_env(t_env *env_ll);

// signals.c
void	signal_interactive(void);
void	signal_not_interactive(void);
void	non_interactive_handler(int sign);
void	interactive_sigint(int sign);
void	signal_child_active(void);

// utils.c
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin_mod(char *str_static, char *buffer);
void	heredoc_exit(int signal);
int		fork_helper(int *pid);
int		check_cmd_token_logic(t_cmd *cmd);

#endif