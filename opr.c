#include <stdio.h>

struct node {
    int data;
    int freq;
    int longest;
};

int search(struct node F[], int page[], int n, int index, int frame, int element) {
    // Check if the element is already in the frame
    for (int i = 0; i < frame; i++) {
        if (F[i].data == element) {
            return i; // Return the position if found
        }
    }
    return -1; // Element not found
}

void update_frames(struct node F[], int page[], int n, int index, int frame) {
    for (int i = 0; i < frame; i++) {
        F[i].longest = -1; // Reset longest for the next round
        for (int j = index + 1; j < n; j++) {
            if (F[i].data == page[j]) {
                F[i].freq++;
                F[i].longest = j; // Store the index of the next use
                break; // Exit the inner loop if found
            }
        }
    }
}

void opr(int page[], int n, int frame) {
    struct node F[frame];
    int hit = 0, fault = 0;

    // Initialize frames
    for (int i = 0; i < frame; i++) {
        F[i].data = -1;
        F[i].freq = 0;
        F[i].longest = -1; // Reset the longest
    }

    for (int i = 0; i < n; i++) {
        int pos = search(F, page, n, i, frame, page[i]);

        if (pos != -1) {
            hit++; // Page hit
        } else {
            fault++; // Page fault
            int done = 0;

            // Add new page to an empty frame
            for (int j = 0; j < frame; j++) {
                if (F[j].data == -1) {
                    F[j].data = page[i];
                    F[j].freq = 1;
                    done = 1;
                    break;
                }
            }

            // If no empty frame, replace the page with the longest future use
            if (!done) {
                int replaceIndex = 0;
                int maxLongest = F[0].longest;

                for (int j = 1; j < frame; j++) {
                    if (F[j].longest == -1 || F[j].longest > maxLongest) {
                        maxLongest = F[j].longest;
                        replaceIndex = j;
                    }
                }
                F[replaceIndex].data = page[i];
                F[replaceIndex].freq = 1; // Reset frequency for the new page
            }
        }

        // Update the frames with the longest future use
        update_frames(F, page, i, frame);

        // Print the current frame contents
        printf("Frame contents after accessing page %d: ", page[i]);
        for (int j = 0; j < frame; j++) {
            printf("%d ", F[j].data);
        }
        printf("\n");
    }

    printf("\nPage Hits: %d\nPage Faults: %d\n", hit, fault);
}

int main() {
    int page[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int frame = 3;
    int n = sizeof(page) / sizeof(page[0]);

    opr(page, n, frame);
    return 0;
}
