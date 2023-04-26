#include <stdio.h>
#include <unistd.h>

/*fork fonksiyonu child process açmak için kullanılır.
child_process thread'ten farklı olarak kopya bir main oluşturur.
ana mainde değişen değer kopya mainde(child_process'te) değişmez
ve aynı şekilde kopya mainde artan değer ana mainde değişmez.
*/

int main() {
    pid_t pid;
     int main_process = 0;
     int child_process = 0;
    pid = fork();  // child process oluştur

     while(1)
     {
          getchar();
          if (pid < 0) 
          { 
               fprintf(stderr, "Fork failed");
               return 1;
          }
          else if (pid == 0)
          {
               printf("Merhaba, ben çocuk süreç!\n");
               child_process++;
          }
          else 
          {
               printf("Merhaba, ben ebeveyn süreç! Çocuk sürecin PID'si: %d\n", pid);
               main_process++;
          }
          printf("CHILD_PROCESS: %d | MAIN PROCESS: %d\n", child_process, main_process);
     }
    return 0;
}