/*
 * Hunter Long
 * mia014
 * CS-3424-0B2
 * May 2nd, 2021
 * Assignment 6
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

int main( int argc, char *argv[] ){

    //if there are no commands there is nothing to do so just exit
    if( argc == 1 ){
        printf( "No commands to run, exiting.\n" );
        return 0;
    }

    //parse the command line arguments into seperate argv[] arrays for each command given  
    int i;
    int numOfCommands = 1;
    int numOfArguments = 0;
    char *arrayOfargvs[6][argc];

    for( i = 1; i < argc; i++){
        
        if( strcmp( argv[i], ":" ) == 0 ){
            numOfCommands++;
            if( numOfCommands >= 7 ){
                printf( "To many commands (a maximum of 6 is allowed), exiting.\n" );
                return 0;
            }
            numOfArguments = 0;
            continue;
        }
        arrayOfargvs[numOfCommands-1][numOfArguments] = argv[i];
        numOfArguments++;
        arrayOfargvs[numOfCommands-1][numOfArguments] = NULL;
    }

    //using the array of argv[] arrays, call fork and execp based on the number of commands that were found    
    i = 0;
    long forkPID[6];
    while( i < numOfCommands ){

        forkPID[i] = fork();

        switch( forkPID[i] ){
            case -1:
                printf( "fork failed: %s", strerror(errno) );
                break;
            case 0:
                fprintf( stderr, "PID: %lu, PPID: %lu, CMD: %s\n", (long) getpid(), (long) getppid(), arrayOfargvs[i][0] );
                execvp( arrayOfargvs[i][0], arrayOfargvs[i] );
                printf( "exec failed, %s\n", strerror(errno) );
                break;
            default:
                break;
        }

        i++;

    }
    
    //ensure no children turn into zombies or orphans by having the parent wait to exit until they all finish executing
    while( wait(NULL) != -1 );

    return 0;

}
