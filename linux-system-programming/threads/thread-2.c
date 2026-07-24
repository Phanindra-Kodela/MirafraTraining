// this is a program to print passed argument to a thread
#include <stdio.h>
#include <pthread.h>

void* worker(void* arg){
    printf("Worker Thread!\n");
    printf("%d\n", *(int*)arg);
    printf("Worker Thread Exited!\n");
}

int main(){

    pthread_t tid;
    int x = 23;
    //create a thread
    pthread_create(&tid, NULL, worker, &x);

    printf("Main Thread!\n");
    // wait for the thread
    pthread_join(tid, NULL);
    printf("Main Thread Exited!\n");

    return 0;
}