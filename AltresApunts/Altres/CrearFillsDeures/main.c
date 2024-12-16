#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void fill() {
    //Generador aleatori
    srand(time(NULL) + getpid());

    int num = rand() % 10;

    exit(num);
}

int main() {
    pid_t pid;
    int status;
    int resultat[5]; // Guardo les respostes de cada fill en una llista

   
    for (int i = 0; i < 5; i++) {
        pid = fork();

        if (pid == -1) {
            perror("Error en crear el fill");
        }

        if (pid == 0) {
            fill();
        }
    }

    for (int i = 0; i < 5; i++) {
        //Espero al resultat d'un fill
        pid_t fill_pid = wait(&status);

        if (WIFEXITED(status)) {
                // Si el fill acaba correctament, guardo el resultat
            resultat[i] = WEXITSTATUS(status);
        } else {
            // Error de fill
            printf("El fill %d no ha acabat correctament.\n", fill_pid);
        }
    }

    printf("Resultat: F%dF%dF%dF%dF%d\n", resultat[0], resultat[1], resultat[2], resultat[3], resultat[4]);

    return 0;
}
