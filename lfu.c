#include <stdio.h>

struct node {
    int data;  // The page number
    int freq;  // The frequency of the page
};

// Function to search for a page in the frame
int search(struct node F[], int frame, int page) {
    for (int i = 0; i < frame; i++) {
        if (F[i].data == page) {
            return i;  // Page found
        }
    }
    return -1;  // Page not found
}

// Function to find the least frequently used page (or least recently added in case of tie)
int findLFU(struct node F[], int frame) {
    int minFreq = F[0].freq;
    int lfuIndex = 0;

    for (int i = 1; i < frame; i++) {
        if (F[i].freq < minFreq) {
            minFreq = F[i].freq;
            lfuIndex = i;
        }
    }
    return lfuIndex;
}

// LFU Page Replacement Algorithm
void lfu(int page[], int frame, int n) {
    struct node F[frame];
    int hit = 0, fold = 0;

    // Initialize frames
    for (int i = 0; i < frame; i++) {
        F[i].data = -1;  // Empty frame
        F[i].freq = 0;   // No frequency initially
    }

    for (int i = 0; i < n; i++) {
        int currentPage = page[i];
        int pos = search(F, frame, currentPage);

        if (pos != -1) {
            // Page hit, increase its frequency
            F[pos].freq++;
            hit++;
        } else {
            // Page fault, find the least frequently used page to replace
            fold++;

            int lfuIndex = findLFU(F, frame);
            F[lfuIndex].data = currentPage;
            F[lfuIndex].freq = 1;  // Reset frequency for the new page
        }

        // Display the current state of frames
        printf("Page %d -> Frames: ", currentPage);
        for (int j = 0; j < frame; j++) {
            if (F[j].data != -1) {
                printf("%d (freq: %d) ", F[j].data, F[j].freq);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total Hits: %d\n", hit);
    printf("Total Page Faults: %d\n", fold);
}

int main() {
    int page[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int n = sizeof(page) / sizeof(page[0]);

    printf("Enter the number of frames: ");
    int frame;
    scanf("%d", &frame);

    lfu(page, frame, n);

    return 0;
}
