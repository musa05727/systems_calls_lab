/*******
 * Filename: finfo.c 
 * Author: Musa Abdul Hamid
 * Lab 9
 * Section 111
 * Date: 11/6/26
 ******/
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){

    if(argc > 1){
        struct stat file_info; 
        // stat() retrieves information about a file, including its type, permissions, owner, size, and modification time.
        if(stat(argv[1], &file_info) == -1){
            perror("stat failed");
            exit(EXIT_FAILURE); 
        }

        printf("File type: ");
        // st_mode contains the file type and permission bits.
        switch (file_info.st_mode & S_IFMT) {
            case S_IFBLK:  printf("block device\n");            break;
            case S_IFCHR:  printf("character device\n");        break;
            case S_IFDIR:  printf("directory\n");               break;
            case S_IFIFO:  printf("FIFO/pipe\n");               break;
            case S_IFREG:  printf("regular file\n");            break;
            case S_IFSOCK: printf("socket\n");                  break;
            default:       printf("unknown?\n");                break;
        }

        printf("Permissions: ");

        printf("%c", (file_info.st_mode & S_IRUSR) ? 'r' : '-');
        printf("%c", (file_info.st_mode & S_IWUSR) ? 'w' : '-');
        printf("%c", (file_info.st_mode & S_IXUSR) ? 'x' : '-');

        printf("%c", (file_info.st_mode & S_IRGRP) ? 'r' : '-');
        printf("%c", (file_info.st_mode & S_IWGRP) ? 'w' : '-');
        printf("%c", (file_info.st_mode & S_IXGRP) ? 'x' : '-');

        printf("%c", (file_info.st_mode & S_IROTH) ? 'r' : '-');
        printf("%c", (file_info.st_mode & S_IWOTH) ? 'w' : '-');
        printf("%c", (file_info.st_mode & S_IXOTH) ? 'x' : '-');

        printf("\n"); 
        // st_uid stores the user ID of the file's owner.
        printf("Owner: %lu\n", (unsigned long)file_info.st_uid); 
        // st_size stores the file size in bytes.
        printf("File size: %lu bytes\n",(unsigned long) file_info.st_size);
        // ctime() converts the file's last modification time into a readable date and time.
        printf("Last file modification: %s", ctime(&file_info.st_mtime)); 
    }else{
        printf("Must specify a file via command line\n"); 
        exit(EXIT_FAILURE); 
    }
    return 0; 
}