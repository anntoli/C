#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubble_sort(int arr[]) {
    int j, last, t;
    last = 1;
    do {
        t = 0;
        for (j = 99; j >= last; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
                t = j;
            }
        }
        last = t;
    } while (t > 0);
}

// Quick Sort
void quick_sort(int arr[], int low, int high) {
    int i, j, x, k;
    i = low;
    j = high;
    k = (low + high) / 2;
    x = arr[k];
    do {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (low < j)
        quick_sort(arr, low, j);
    if (i < high)
        quick_sort(arr, i, high);
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


//Selection Sort
void selection_sort(int arr[]) {
	int i, j, x, k;
	
	for (i=(100-1); i >= 1; i--) {
		x = arr[i];
		k = i;
		for (j = i; j >= 0; j--) {
			if (arr[j] > x) {
				k = j;
				x = arr[j];
			}
		}
		swap(&arr[i], &arr[k]);
	}
}

// Insertion Sort
void insertion_sort(int arr[]) {
	int i, j, t;
	
	for (j=1; j < 100; j++) {
		i = j - 1;
		t = arr[j];
		do {
			if (t >= arr[i])
				break;
			arr[i+1] = arr[i];
			i--;
		} while (i >= 0);
		arr[i+1] = t;
	}
}

// Shell Sort
void shell_sort(int arr[]) {
	int i, j, s, pas, qq;
	double h[20];
	
	for (i=0; i <= 19; i++) 
		h[i] = pow(2, i);
	
	for (s=19; s >= 0; s--) {
		pas = h[s];
		for (j = pas; j < 100; j++) {
			i = j - pas;
			qq = arr[j];
			do {
				if (qq >= arr[i]) 
					break;
				arr[i+pas] = arr[i];
				i = i - pas;
			} while (i >= 0);
			arr[i+pas] = qq;
		}
	}
}


// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}


int main() {
    
    int arr[1000]; 
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000000 + 1; 
    }


    clock_t start_time, end_time;
    double bubble_sort_time, quick_sort_time, merge_sort_time, selection_sort_time, insertion_sort_time, shell_sort_time, heap_sort_time;

    
    start_time = clock();
    bubble_sort(arr);
    end_time = clock();
    bubble_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    quick_sort(arr, 0, 99);
    end_time = clock();
    quick_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    merge_sort(arr, 0, 99);
    end_time = clock();
    merge_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    selection_sort(arr);
    end_time = clock();
    selection_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    insertion_sort(arr);
    end_time = clock();
    insertion_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    shell_sort(arr);
    end_time = clock();
    shell_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    heap_sort(arr, 1000);
    end_time = clock();
    heap_sort_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %.6f seconds\n", bubble_sort_time);
    printf("Quick Sort Time: %.6f seconds\n", quick_sort_time);
    printf("Merge Sort Time: %.6f seconds\n", merge_sort_time);
    printf("Selection Sort Time: %.6f seconds\n", selection_sort_time);
    printf("Insertion Sort Time: %.6f seconds\n", insertion_sort_time);
    printf("Shell Sort Time: %.6f seconds\n", shell_sort_time);
    printf("Heap Sort Time: %.6f seconds\n", heap_sort_time);

    return 0;
}
