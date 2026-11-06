/*******
 * Filename: pmod.c 
 * Author: Musa Abdul Hamid
 * Lab 9
 * Section 111
 * Date: 11/6/26
 ******/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>


int main(int argc, char* argv[]){
    struct timespec ts; 
    ts.tv_nsec =  837272638;
    //1 second -> 1,000,000,000 ns
    ts.tv_sec = 1; 

    //total time(ns) -> 1837272638ns
     
    int reduced_priority = nice(10); 
    printf("Priority: %d\n", reduced_priority);  
    nanosleep(&ts, NULL);
    printf("Goodbye!\n"); 
    exit(EXIT_SUCCESS); 

    return 0; 
}
