#include "minishell.h"


void split_path(t_data *data, char **env)
{
     int i = 0;
     int j = 0;
     char *str;
     while(env[i])
     {
          j = 0;
          while(env[i][j])
          {
               if(env[i][j] == 'P')
               {
                    j++;
                    if(env[i][j] == 'A' && env[i][j + 1] == 'T' && env[i][j + 2] == 'H')
                    {
                         j += 4;
                         str = env[i] + j;
                         data->path = ft_split(str, ':');
                         return ;
                    }
               }
               j++;
          }
          i++;
     }
}

char *ft_strncpy(char *dst, char *src, int len)
{
     int i = 0;
     while(i < len && src[i])
     {
          dst[i] = src[i];
          i++;
     }
     return dst;
}

int path_finder(t_data *data, char **av, char **env, char **input)
{
     int i = 0;
     int j = 0;
     char *full_path;
     int len;

     while(data->path[i])
     {
          full_path = malloc (ft_strlen(data->path[i]) + ft_strlen(input[0]) + 2);
          ft_strncpy(full_path, data->path[i], ft_strlen(data->path[i]));
          len = ft_strlen(full_path);
          full_path[len] = '/';
          full_path = ft_strjoin(full_path, input[0]);
          if(access(full_path, X_OK) != -1)
          {
               if(data->splited_input[1])
                    execve(full_path, data->splited_input, env);
               else
                    execve(full_path, av, env);

               return 1;
          }
          full_path = NULL;
          i++;
     }
     printf("Command not found!");
     return 0;
}

int main(int ac, char **av, char **env)
{
     int i = 0;
     int j = 0;
     char *input;
     pid_t pid;
     t_data *data;
     data = malloc (sizeof(t_data));
     while(1)
     {
          split_path(data, env);
          input = readline("\nminibash: ");
          data->splited_input = ft_split(input, ' ');
          pid = fork();
          if(pid == 0)
          {
               path_finder(data, av, env, data->splited_input);
               exit(1);
          }
          wait(&pid);
     }
}