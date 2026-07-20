// this is a program to write a mini-shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(){

    // run the shell
    while(1){
        // 1. prompt : myshell>
        printf("myshell>");
        fflush(stdout); // real shell always flushed the output

        // 2. read commands using fgets()
        char line[1024];
        if(fgets(line, sizeof line, stdin) == NULL){
            // check if user enter CTRL+D
            puts(""); break;
        }

        // 3. format the command by ignoring new line
        // *strchr(line, '\n') = '\0'; // can crash if input size > 1023
        char *p = strchr(line, '\n');
        if(p) *p = '\0';

        // if user enters new line
        if(strlen(line) == 0) continue; 

        // 4. parse the input using strtok()
        char *token = strtok(line, " ");
        char *args[100];
        int i = 0;
        while(token){
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
    
        // 5. check built-in command
        if(strcmp(args[0], "exit") == 0) break;

        // 6. execute external commands
        pid_t pid = fork();

        // fork fails
        if(pid == -1){
            perror("fork");
            continue;
        }

        if(pid == 0){
            // child process -> execute the user command
            
            execvp(args[0], args);
            
            // if invalid command
            perror("execvp");
            _exit(EXIT_FAILURE);
        }else{

            waitpid(pid, NULL, 0);
        }

    }
    
    return 0;
}
