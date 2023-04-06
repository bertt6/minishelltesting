#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
     char* line;
     line = readline("Lütfen isminizi giriniz: ");
     add_history(line);
     add_history("geldiii");
     line = readline("Lütfen soyisminizi girin: ");
     add_history(line);
     line = readline("Lütfen memleketinizi girin: ");
     add_history(line);
     printf("%s\n", line);

}