#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

//dup2 fonksiyonu fd'leri eşitlemek için kullanılır.

int main() {
    int fd1, fd2, fd3;
    char buf[100];

    fd1 = open("file1.txt", O_RDONLY); // dosyayı okumak için aç
    if (fd1 == -1) {
        perror("open"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }

    fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0666); // dosyayı yazmak için aç
    if (fd2 == -1) {
        perror("open"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }

    fd3 = dup(fd1); // fd1'in bir kopyasını oluştur
    if (fd3 == -1) {
        perror("dup"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }

    // fd3'ü fd1'e eşitle
    if (dup2(fd3, fd1) == -1) {
        perror("dup2"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }

    // fd1'den oku ve fd2'ye yaz
    while (read(fd1, buf, 50) > 0) {
        if (write(fd2, buf, strlen(buf)) == -1) {
            perror("write"); // hata mesajını yazdır
            exit(EXIT_FAILURE);
        }
    }

    close(fd1); // dosya tanıtıcısını kapat
    close(fd2); // dosya tanıtıcısını kapat
    return 0;
}
