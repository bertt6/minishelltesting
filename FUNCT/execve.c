#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

/*execve kullanacağımız (örneğin man) kodunun yolunu verip
o kodu o yolu kullanarak çalıştırmamıza yarar. 2. parametre olarak 
man yapacağınız (örneğin strlen) fonksiyonu yazmalısınız.
3. parametre olarak ise environmentleri almalıdır.*/

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