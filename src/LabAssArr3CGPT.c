#include <stdio.h>
#include <stdlib.h>

int removedupl_k(int a[], int len, int k) {
    // Handle edge case where array length is 0 or 1
    if (len == 0) return 0;
    
    // Step 1: Count frequency of each element
    int *freq = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        freq[i] = -1;  // Initialize frequency array with -1 to indicate unvisited elements
    }
    
    for (int i = 0; i < len; i++) {
        if (freq[i] == -1) {  // If the element hasn't been counted yet
            int count = 0;
            for (int j = i; j < len; j++) {
                if (a[i] == a[j]) {
                    count++;
                    freq[j] = count;  // Store the count for all occurrences of the element
                }
            }
        }
    }
    
    // Step 2: Modify the array to remove duplicates
    int new_len = 0;
    for (int i = 0; i < len; i++) {
        if (freq[i] < k) {  // Keep element if it appears less than k times
            a[new_len++] = a[i];
        } else if (freq[i] == k && i == 0) { // If it appears exactly k times, keep one occurrence
            a[new_len++] = a[i];
        }
    }

    free(freq); // Free the frequency array
    
    return new_len;
}

// Function to print the array (for testing)
void print_array(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 1 , 3, 4 , 1, 3 , 2 ,4 , 3}; 
    int len = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    int new_len = removedupl_k(arr, len, k);
    
    printf("Array after removing duplicates: ");
    print_array(arr, new_len);
    
    printf("New length: %d\n", new_len);
    
    return 0;
}

