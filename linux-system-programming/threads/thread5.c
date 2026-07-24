// this is a program where multiples threads write to shared memory location.

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* worker(void* arg){
    printf("Thread Entered!\n");
    for(int i = 0; i < 1e6; i++)
        counter++;
    printf("Thread Exited!\n");
}

int main(){

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, worker, NULL);
    pthread_create(&tid2, NULL, worker, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Counter: %d\n", counter);

    return 0;
}