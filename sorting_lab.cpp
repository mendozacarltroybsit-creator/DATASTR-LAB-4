

#include <iostream>
#include <algorithm>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swapping occurred, array is already sorted
        if (!swapped) break;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

// Merge Sort Helper Functions
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

// Merge Sort
void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

// Quick Sort Helper Functions
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

// Quick Sort
void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

// Heap Sort Helper Functions
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Utility function to copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 10;
    int originalArr[n], arr[n];
    
    cout << "Enter 10 integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> originalArr[i];
    }
    
    int choice;
    do {
        // Copy original array to working array
        copyArray(originalArr, arr, n);
        
        cout << "\n==============================================";
        cout << "\nChoose Sorting Algorithm:";
        cout << "\n[1] Bubble Sort";
        cout << "\n[2] Insertion Sort";
        cout << "\n[3] Selection Sort";
        cout << "\n[4] Merge Sort";
        cout << "\n[5] Quick Sort";
        cout << "\n[6] Heap Sort";
        cout << "\n[7] Shell Sort";
        cout << "\n[8] Exit";
        cout << "\nEnter your choice (1-8): ";
        cin >> choice;
        
        if (choice >= 1 && choice <= 7) {
            cout << "\nOriginal Array: ";
            printArray(arr, n);
            
            switch (choice) {
                case 1: 
                    bubbleSort(arr, n);
                    cout << "After Bubble Sort: ";
                    break;
                case 2: 
                    insertionSort(arr, n);
                    cout << "After Insertion Sort: ";
                    break;
                case 3: 
                    selectionSort(arr, n);
                    cout << "After Selection Sort: ";
                    break;
                case 4: 
                    mergeSort(arr, n);
                    cout << "After Merge Sort: ";
                    break;
                case 5: 
                    quickSort(arr, n);
                    cout << "After Quick Sort: ";
                    break;
                case 6: 
                    heapSort(arr, n);
                    cout << "After Heap Sort: ";
                    break;
                case 7: 
                    shellSort(arr, n);
                    cout << "After Shell Sort: ";
                    break;
            }
            
            printArray(arr, n);
        } else if (choice != 8) {
            cout << "Invalid choice! Please try again.\n";
        }
        
    } while (choice != 8);
    
    cout << "Program exited. Thank you!\n";
    return 0;
}