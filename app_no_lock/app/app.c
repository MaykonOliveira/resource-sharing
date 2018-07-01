#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>

#include <time.h>
#include <sys/time.h>

#define N 5

int main()
{
    char hostname[1024];
    gethostname(hostname, 1024);
    int n = N;

    FILE *arq;
    
    while(n--){
        struct timeval uSec;
        time_t current_time = time(0);
        gettimeofday(&uSec, NULL);
        struct tm *current = localtime(&current_time);
        arq = fopen("/shared_file/file.txt", "a+");
        if (!arq){
            perror("Arquivo inexistente");
            exit(0);
        }
        fprintf(arq, "ID da maquina: %s - Hora: %d:%d:%d\n", hostname, current->tm_hour, current->tm_min, current->tm_sec);
        sleep(3);
        fclose(arq);
    }   
    return 0;
}