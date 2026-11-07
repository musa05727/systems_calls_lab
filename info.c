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
    // clock_gettime() retrieves the current time in seconds and nanoseconds.
    if(clock_gettime(CLOCK_REALTIME, &res) == -1){
        printf("clock_gettime failed\n"); 
        return 1; 
    }
    long long ns = (long long)res.tv_sec * 1000000000LL + res.tv_nsec; 

    printf("Current time of day since epoch(ns): %lld\n",ns); 

    struct utsname info; 
    
    // uname() retrieves operating system and hardware information.
    if(uname(&info) == 0){
        //Network name
        if(info.nodename[0] != '\0'){
            printf("Network name: %s\n", info.nodename); 
        }
        if(info.sysname[0] != '\0'){
             //System name 
            printf("System Name: %s\n", info.sysname); 
        }
        if(info.release[0] != '\0'){
            //Os release
            printf("Release: %s\n", info.release);
        }
        if(info.version[0] != '\0'){
            //Os version
             printf("Version: %s\n", info.version);
        }
        if(info.machine[0] != '\0'){
             //hardware type
            printf("Hardware Type: %s\n", info.machine);
        }
    }else{
        printf("error when calling uname function\n"); 
        return 1; 
    }
    // get_nprocs_conf() returns the number of configured processors.
    printf("Number of processors: %d\n", get_nprocs_conf()); 
    
    // sysconf() retrieves system configuration values, such as memory pages and page size.
    long long physical_mem_bytes = (long long)sysconf(_SC_PHYS_PAGES)* sysconf(_SC_PAGESIZE); 
    printf("Physical Memory in bytes: %lld\n", physical_mem_bytes);  

    long long rem_mem_bytes = (long long)sysconf(_SC_AVPHYS_PAGES)* sysconf(_SC_PAGESIZE); 
    printf("Remaining Memory in bytes: %lld\n", rem_mem_bytes);
    return 0;
 }