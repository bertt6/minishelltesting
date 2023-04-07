#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "readline/readline.h"

typedef struct s_data
{
     char **path;
     char **str;
     char **splited_input;
}              t_data;


char	*ft_strjoin(char const *s1, char const *s2);
int	ftcount(char const *s, char c);
char	**ft_split(char const *s, char c);
void split_path(t_data *data ,char **env);
int ft_strlen(const char *str);


#endif