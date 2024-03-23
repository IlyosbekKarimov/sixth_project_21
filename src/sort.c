#include <stdio.h>

#define NMAX 10

int reading(int *arr);
void sorting(int *arr);
void output(int *arr);

int main() {
    int arr[NMAX];
    if (!reading(arr)) {
        printf("n/a");
        return 0;
    }
    if (getchar() == ' ') {
        printf("n/a");
        return 0;
    }
    sorting(arr);
    output(arr);
    return 0;
}

int reading(int *arr) {
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

void sorting(int *arr) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void output(int *arr) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", arr[i]);
    }
}