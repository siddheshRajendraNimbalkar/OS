// #include <stdio.h>

// // Function to search for a page in the frame
// int search(int F[], int frame, int page) {
//     for (int i = 0; i < frame; i++) {
//         if (F[i] == page) {
//             return i; // Page found in frame
//         }
//     }
//     return -1; // Page not found in frame
// }

// // Function to implement the LRU page replacement algorithm
// void lru(int page[], int frame, int n) {
//     int F[frame];  // Array representing the frame
//     int time[frame];  // Array to track the last access time of pages
//     int hit = 0, fault = 0, counter = 0;

//     // Initialize frames and time
//     for (int i = 0; i < frame; i++) {
//         F[i] = -1;  // Empty frame
//         time[i] = 0;  // Initial time
//     }

//     printf("\nReference String: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", page[i]);
//     }
//     printf("\n");

//     for (int i = 0; i < n; i++) {
//         int ser = search(F, frame, page[i]);

//         // Start from ser != -1 (Page Hit)
//         if (ser != -1) {
//             // Page hit occurs
//             hit++;
//             time[ser] = ++counter;  // Update the time for the page hit
//         } else {
//             // Page fault occurs
//             fault++;
//             int lru_index = 0;

//             // Find the least recently used (LRU) page's index
//             for (int j = 1; j < frame; j++) {
//                 if (time[j] < time[lru_index]) {
//                     lru_index = j;
//                 }
//             }

//             // Replace the LRU page with the current page
//             F[lru_index] = page[i];
//             time[lru_index] = ++counter;  // Update the time for the newly inserted page
//         }

//         // Print the current state of frames
//         printf("Frame contents after accessing page %d: ", page[i]);
//         for (int j = 0; j < frame; j++) {
//             if (F[j] == -1) {
//                 printf("- ");
//             } else {
//                 printf("%d ", F[j]);
//             }
//         }
//         printf("\n");
//     }

//     // Print the total number of hits and faults
//     printf("\nTotal Page Hits: %d\n", hit);
//     printf("Total Page Faults: %d\n", fault);
// }

// int main() {
//     int page[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
//     int frame;

//     // Input the number of frames
//     printf("Enter the number of frames: ");
//     scanf("%d", &frame);

//     int n = sizeof(page) / sizeof(page[0]);

//     // Call the LRU function to simulate demand paging
//     lru(page, frame, n);

//     return 0;
// }


#include<stdio.h>

struct Time{
    int data;
    int time;
};

int search(struct Time T[],int frame,int page){
    for(int i=0;i<frame;i++){
        if(T[i].data==page){
            return i;
        }
    }
    return -1;
}

void lru(int page[],int frame,int n){
    struct Time T[frame];
    int hit=0,fault=0;

    for(int i=0;i<frame;i++){
        T[i].data=-1;
        T[i].time=0;
    }

    for(int i=0;i<n;i++){
        int pos=search(T,frame,page[i]);

        if(pos!=-1){
            T[pos].time++;
            hit++;
        }else{
            fault++;
            int lru_index=0;
            for(int j=1;j<frame;j++){
                if(T[j].time<T[lru_index].time){
                    lru_index=j;
                }
            }
            T[lru_index].data=page[i];
            T[lru_index].time=1;
        }
    }
    printf("\nPage Hits: %d\nPage Faults: %d\n",hit,fault);
}

int main() {

    int page[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int frame=3;
    int n = sizeof(page)/sizeof(page[0]);

    lru(page,frame,n);
    return 0;
}