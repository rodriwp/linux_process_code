//Practica 1: Ejercicio numero uno
//@author Rodrigo Mompó Redoli

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
    pid_t pid = 0;
    printf("El padre esta ejecutando . . . \n");
    pid = fork();
    if (pid < 0){ /* error occurred */
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { /* child process */
        pid = fork();
        if (pid < 0){ /* error occurred */
            perror("Fork Failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { /* grandchild process */
            int ret2 = execlp("./fecha","fecha",NULL);
            if (ret2 == -1) {
            perror("execl");
            }
        }
        else { /* child process */
            int ret = execl("/bin/ls", "ls", NULL);
            if (ret == -1) {
            perror("execl");
            }
        }
    }
    else { /* parent process */
            //TODO: parent process
    }
}
