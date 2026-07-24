// this is a program to read a returned value from a thread
#include <pthread.h>
#include <stdio.h>

void* worker(void* arg){
    // thread worker

    printf("Thread Entered!\n");

    static int num = 11;

    // multiply with passed argument
    int amplifier = *(int*)arg;

    printf("Thread variable value: %d\nPassed argument: %d\n", num, amplifier);
    num *= amplifier;

    printf("Thread exited!\n");
    return &num;
}

int main(){

    pthread_t tid;

    int multiplier = 3;
    pthread_create(&tid, NULL, worker, &multiplier);

    void* res;
    pthread_join(tid, &res);

    int RESULT = *(int*)res;
    printf("Result from Thread: %d\n", RESULT);

    return 0;
}