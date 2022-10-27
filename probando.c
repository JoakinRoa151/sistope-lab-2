#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define LECTURA 0
#define ESCRITURA 1

int main(int argc, char *argv[]) {
    int pipefd1[2], pipefd2[2];
    char buffer1[100], buffer2[100];
    pipe(pipefd1);
    pipe(pipefd2);
    int status1 , status2;
    int pid1, pid2; 
    pid1 = fork();
    pid2 = fork();
    //El hijo escribe y el padre lee, pero con exec y dup2
    if (pid1 == 0) {
        dup2(pipefd1[ESCRITURA],STDOUT_FILENO); //STDOUT_FILENO = un int que tiene el descriptor de stdout.
        close(pipefd1[LECTURA]);              // no usamos lectura

        execl("./h","./h", NULL);
        printf("HOLA\n");
        perror("exec ls failed");
        exit(EXIT_FAILURE);
    }
    else if(pid2 == 0) {
        dup2(pipefd2[ESCRITURA],STDOUT_FILENO); //STDOUT_FILENO = un int que tiene el descriptor de stdout.
        close(pipefd2[LECTURA]);              // no usamos lectura

        execl("./h","./h", NULL);
        printf("HOLA\n");
        perror("exec ls failed");
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status1);
        wait(&status2);
        read(pipefd1[LECTURA], buffer1, 100); //leemos el pipe y lo imprimimos
         read(pipefd2[LECTURA], buffer2, 100); //leemos el pipe y lo imprimimos
        printf("Hijo1 dice: %s\n", buffer1);
         printf("Hijo2 dice: %s\n", buffer2);
    }


    return 0;
}
