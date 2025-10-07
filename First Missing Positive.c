#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to return the first missing positive number
int firstMissingPositive(int arr[], int n) {
    int i;

    // Place each positive integer at its correct position
    for (i = 0; i < n; ++i) {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }

    // Find the first place index where arr[i] != i+1
    for (i = 0; i < n; ++i) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    // If all positions are filled correctly
    return n + 1;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int missing = firstMissingPositive(arr, n);
    printf("The first missing positive is %d\n", missing);
    return 0;
}
