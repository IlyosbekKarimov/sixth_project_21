#include <stdio.h>

#define NMAX 10

int reading(int *arr);
void output(int *arr);
void quick_sort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void heapsort(int *arr, int n);
void build_heap(int *arr, int n);
void heapify(int *arr, int n, int i);
void swap(int *a, int *b);

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
    quick_sort(arr, 0, NMAX - 1);
    output(arr);
    puts("");
    heapsort(arr, NMAX);
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

void output(int *arr) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", arr[i]);
    }
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void heapsort(int *arr, int n) {
    build_heap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void build_heap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}