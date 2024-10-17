#include <stdio.h>
#include <stdlib.h>

// Binary search function
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Item not found
}

int main(int argc, char *argv[]) {
    // Array size is argc - 2 (excluding program name and search item)
    int n = argc - 2;
    int arr[n];

    // Convert command-line arguments back into integers
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    // Search item is the last argument
    int search_item = atoi(argv[argc - 1]);

    // Perform binary search
    int result = binarySearch(arr, n, search_item);

    if (result != -1) {
        printf("Item %d found at index %d\n", search_item, result);
    } else {
        printf("Item %d not found in the array\n", search_item);
    }

    return 0;
}
