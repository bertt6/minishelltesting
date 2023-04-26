#include <stdio.h>
#include <unistd.h>

//change directory fonksiyonu path'i (yolu) değiştirmemize yarar.

int main() {
    char *path = "/Users/bsamli/Desktop/minishell";
    if (chdir(path) == 0) {
        printf("Working directory changed to %s\n", path);
    } else {
        perror("chdir() error");
        return 1;
    }
    return 0;
}