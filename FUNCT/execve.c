#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>


int main(int ac, char **av, char **env) {
     char *input;
     while (1)
     {
     input = readline("$");
     printf("%s\n", input);
     execve("/usr/bin/man", av, env);
     }
     
   return 0;
}