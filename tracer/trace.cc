/*
    Last Modified: June 8, 2025
    Last Update: Created child process, declared child process as tracee
    TODO next: Check over tracee process, Add tracing logic in parent process
    Custom System Call Tracer: 
        - Tracks system calls made by kernel for specified program
        - Runs specified process until exit status reached
        - Uses ptrace interface to allow current process become parent of specified process
        - Current process (parent) monitors child process and stops regularly at syscalls

*/

//test comment
//Remove unneccesary includes at end
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <sstream>
#include <sys/ptrace.h> //Necessary for ptrace



int main(char * argv[], int argc) {

    //Improper Call Error 
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prog> [args]\n", argv[0]); exit(1);
    }

    //Creating Child Process for Tracee
    pid_t pid = fork(); 

    //Executing child process as tracee 
    if (pid == 0) { //Signals that currently in child process
        ptrace(PTRACE_TRACEME, 0, NULL, NULL); // Child process declaring itself as tracee
        execvp(argv[1], &argv[1]);
        perror("execvp error"); //Shouldn't reach here if execvp successful
        exit(1);
    }

    //Currently in parent/tracer process

    //Add waiting for parent process

    //Next need to add entry point and exit logic for each system call 



}






