#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// add_history fonksiyonu terminal içerisindeki ok tuşları ile 
//geçmişte yazılan kodları eklemek, çıkarmak vb. işlemler için kullanılır.

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