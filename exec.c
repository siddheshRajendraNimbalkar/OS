#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For fork(), execve()
#include <sys/wait.h> // For wait()
#include <string.h>   // For string manipulation

// Bubble sort function for parent process
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {  // j starts at 1 (i+1)
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Main program that forks and passes sorted array to child
int main() {
    int n, search_item;
    pid_t pid;

    // Accepting size of array
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Allocating space for the array
    int arr[n];
    char *argv[n + 3];  // For execve arguments, +3 for program name, search item, and NULL terminator
    char buffer[10];    // Buffer to store integer strings for execve

    // Accepting integers
    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Accepting the search item
    printf("Enter the item to search: ");
    scanf("%d", &search_item);

    // Sorting the array using bubble sort
    bubbleSort(arr, n);

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process

        // Preparing arguments for execve()
        argv[0] = "./execCode";  // Program to load
        for (int i = 1; i < n; i++) {
            sprintf(buffer, "%d", arr[i-1]);  // Convert each sorted integer to string
            argv[i] = strdup(buffer);   // Store in argv
        }
        // Add search item as the second last argument
        sprintf(buffer, "%d", search_item);
        argv[n + 1] = strdup(buffer);

        // NULL terminator for execve argument list
        argv[n + 2] = NULL;

        // Execute the new program for binary search
        if (execve("./execCode", argv, NULL) == -1) {
            perror("Error executing binary search program");
        }

        // Freeing allocated memory for the arguments
        for (int i = 1; i <= n + 1; i++) {
            free(argv[i]);
        }

        exit(0); // Child process exits after execve()
    } else {
        // Parent process waits for the child process to finish
        wait(NULL);
        printf("Parent Process: Child finished searching.\n");
    }

    return 0;
}
