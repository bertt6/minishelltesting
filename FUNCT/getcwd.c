#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*getcwd fonksiyonu açılımlı mevcut çalışma 
dizini alan (get current working directory) fonksiyondur */

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
    return 0;
}