/*******
 * Filename: info.c 
 * Author: Musa Abdul Hamid
 * Lab 9
 * Section 111
 * Date: 11/3/26
 ******/

 #include <stdio.h>
 #include <sys/utsname.h>
 #include <sys/sysinfo.h>
 #include <time.h>
 #include <unistd.h>
 

 int main(int argc , char* argv[]){
    struct timespec res; 
    
    if(clock_gettime(CLOCK_REALTIME, &res) == -1){
        printf("clock_gettime failed\n"); 
        return 1; 
    }
    long long ns = (long long)res.tv_sec * 1000000000LL + res.tv_nsec; 

    printf("Current time of day since epoch(ns): %llu\n",ns); 

    struct utsname info; 
    //uname success
    if(uname(&info) == 0){
        //Network name
        printf("Network name: %s\n", info.nodename); 
        //System name 
        printf("System Name: %s\n", info.sysname); 
        //Os release
        printf("Release: %s\n", info.release);
        //Os version
        printf("Version: %s\n", info.version);
        //hardware type
        printf("Hardware Type: %s\n", info.machine);
    }else{
        printf("error when calling uname function\n"); 
        return 1; 
    }

    printf("Number of processors: %d\n", get_nprocs_conf()); 
    //since wsl uses 50% of the total physical memory, I multiplied by 2 to get the actual total. 
    long long physical_mem_bytes = 2 * (long long)sysconf(_SC_PHYS_PAGES)* sysconf(_SC_PAGESIZE); 
    printf("Physical Memory in bytes: %llu\n", physical_mem_bytes);  

    long long rem_mem_bytes = (long long)sysconf(_SC_AVPHYS_PAGES)* sysconf(_SC_PAGESIZE); 
    printf("Remaining Memory in bytes: %llu\n", rem_mem_bytes);
    return 0;
 }