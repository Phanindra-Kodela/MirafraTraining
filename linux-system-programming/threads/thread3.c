// this is a program to print a passed struct argument to a thread.
#include <pthread.h>
#include <stdio.h>

struct Student{
    char name[20];
    int age;
};

void* worker(void* arg){
    printf("Thread Entered!\n");
    struct Student* s = (struct Student*)arg;
    printf("Student name: %s\n", s->name);
    printf("Student age: %d\n", s->age);
    printf("Thread Exited!\n");
}
int main(){

    pthread_t tid;

    struct Student s = {.age = 23, .name = "Phanindra"};
    pthread_create(&tid, NULL, worker, &s);

    pthread_join(tid, NULL);
    return 0;
}