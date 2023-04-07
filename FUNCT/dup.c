#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {
    int fd1, fd2;
    char buf[100];

    fd1 = open("file.txt", O_RDONLY); // dosyayı okumak için aç
    if (fd1 == -1) {
        perror("open"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }

    fd2 = dup(fd1); // fd1'in bir kopyasını oluştur

    // fd1'den oku
    if (read(fd1, buf, 50) == -1) {
        perror("read"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }
    printf("fd1: %s", buf);

    // fd2'den oku
    if (read(fd2, buf, 50) == -1) {
        perror("read"); // hata mesajını yazdır
        exit(EXIT_FAILURE);
    }
    printf("fd2: %s", buf);

    close(fd1); // dosya tanıtıcısını kapat
    close(fd2); // dosya tanıtıcısının kopyasını kapat
    return 0;
}
