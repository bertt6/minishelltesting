#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/*
    ioctl () sistem çağrısı , temel alınan cihazı yönetir
    fd bağımsız değişkeni bir olmalıdır dosya tanıtıcıyı açın.
    İkinci argüman, cihaza bağlı bir istek kodudur.
    üçüncü bağımsız değişken, belleğe yazılmamış bir işaretçidir.
    */

/* pipe fonksiyonu hem standart output'u olan hem standart in'li bir fd oluşturur.*/


int main() {
    int fd[2];
    pid_t pid;
    char buffer[20];

    if (pipe(fd) == -1) { // pipe oluştur
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork(); // çocuk işlemi oluştur

    if (pid < 0) { // hata durumu
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // çocuk işlem
        close(fd[0]); // okuma için kullanılan dosya tanıtıcısını kapat

        char *str = "Merhaba Dünya!";
        write(fd[1], str, strlen(str) + 1); // yazma işlemi yap

        close(fd[1]); // yazma için kullanılan dosya tanıtıcısını kapat
        exit(EXIT_SUCCESS);
    } else { // ebeveyn işlem
        close(fd[1]); // yazma için kullanılan dosya tanıtıcısını kapat

        read(fd[0], buffer, sizeof(buffer)); // okuma işlemi yap
        printf("Çocuk işlem tarafından gönderilen veri: %s\n", buffer);

        close(fd[0]); // okuma için kullanılan dosya tanıtıcısını kapat

        wait(NULL); // çocuk işlemi beklet
        exit(EXIT_SUCCESS);
    }
}
