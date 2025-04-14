///////////////////////////|
//|File: pth_hello.c
//|Author: Jerrin C. Redmon
//|Language: C
//|Version: 1.0.0
//|Date: April 14, 2025
///////////////////////////|

/* Descriptiion:
* This program demonstrates the use of pthreads to create multiple threads
* that print a message to the console. Each thread prints its ID and the total
* number of threads created. The program takes the number of threads as a command
* line argument.
*/

//----------------------------------------------------------------

// Includes //
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// say hello //
void* say_hello(void* arg) {    // Function to be executed by each thread
    int thread_id = *(int*)arg; // Get the thread ID
    int total_threads = *((int*)arg + 1);   // Get the total number of threads
    printf("Hello from thread %d of %d on host\n", thread_id, total_threads);
    free(arg); // Free the dynamically allocated memory
    return NULL;
}

// Main //
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads <= 0) {     // Check if the number of threads is valid
        fprintf(stderr, "Number of threads must be a positive integer.\n");
        return 1;
    }

    pthread_t* threads = malloc(sizeof(pthread_t) * num_threads);   // Allocate memory for thread IDs

    for (int i = 0; i < num_threads; i++) {
        int* args = malloc(sizeof(int) * 2); // Allocate memory for thread arguments
        args[0] = i;
        args[1] = num_threads;
        pthread_create(&threads[i], NULL, say_hello, args);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL); // Wait for each thread to finish
    }

    free(threads);      // Free the allocated memory for thread IDs
    return 0;
}
