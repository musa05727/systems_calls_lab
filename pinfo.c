/*******
 * Filename: info.c 
 * Author: Musa Abdul Hamid
 * Lab 9
 * Section 111
 * Last Updated: 11/3/26
 ******/
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>

const char *scheduler_string(int return_val); 
int main(int argc, char* argv[]){
    int id; 
    int priority; 
    const char *scheduler; 

    if(argc > 1){
        id = atoi(argv[1]); 
        errno = 0; 
        priority = getpriority(PRIO_PROCESS, id); 
        if(priority == -1 && errno != 0){
            perror("getpriority failed"); 
            exit(EXIT_FAILURE); 
        }
        printf("Current executing process: %d\n", id); 
        printf("Priority:%d\n", priority);
        int policy = sched_getscheduler(id); 
        if(policy == -1){
            perror("sched_getscheduler failed");
            exit(EXIT_FAILURE); 
        }
        scheduler = scheduler_string(policy); 
        printf("Scheduler: %s\n", scheduler);   

    }else{
        id = getpid(); 
        printf("Current executing process: %d\n", id);
        errno = 0;  
        priority = getpriority(PRIO_PROCESS, 0);
        if(priority == -1 && errno != 0){
            perror("getpriority failed");
            exit(EXIT_FAILURE);
        } 
        printf("Priority:%d\n", priority);
        int policy = sched_getscheduler(id); 
        if(policy == -1){
            perror("sched_getscheduler failed");
            exit(EXIT_FAILURE); 
        }
        scheduler = scheduler_string(policy); 
        printf("Scheduler: %s\n", scheduler); 
    }
    return 0; 
}
const char *scheduler_string(int return_val){
    switch (return_val)
    {
    case SCHED_OTHER:
        return "SCHED_OTHER (Normal)"; 
    case SCHED_FIFO: 
        return "SCHED_FIFO"; 
    case SCHED_RR: 
        return "SCHED_RR";  
    case SCHED_BATCH: 
        return "SCHED_BATCH"; 
    case SCHED_IDLE: 
        return "SCHED_IDLE"; 
    case SCHED_DEADLINE: 
        return "SCHED_DEADLINE"; 
    default:
        return "ERROR"; 
    }
}