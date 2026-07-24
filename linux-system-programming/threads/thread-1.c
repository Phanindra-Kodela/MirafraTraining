// this is a program to create a simple thread and run it

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // pthread_create() api

// function to be executed by a thread
void* worker(void* arg){
    for(int i = 0; i < 5000; i++)
        write(1, "Hello from worker thread!\n", 27);
    return NULL;
}

int main(){

    pthread_t tid;
    // int pthread_create(pthread_t* p, const pthread_attr_t *attr, void* (*start_routine)(void*), void* arg);
    int x = pthread_create(&tid, NULL, worker, NULL);

    if(x!=0) {
        perror("pthread");
    }
    for(int i = 0; i < 5000; i++)
        write(1, "hello from main thread!\n", 24);
    
    //wait for the thread to finish execution
    pthread_join(tid, NULL);

    return 0;
}