
#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    // Sorted integer array of 10 elements
    int arr[] = {12, 25, 37, 45, 56, 67, 72, 81, 90, 100};
    int n = 10, key, choice, result;
    
    // Display the array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
    
    // Get target element from user
    cout << "Enter element to search: ";
    cin >> key;
    
    // Let user choose search algorithm
    cout << "Choose Searching Algorithm:\n";
    cout << "[1] Linear Search\n[2] Binary Search\n[3] Interpolation Search\nChoice: ";
    cin >> choice;
    
    // Perform search based on user choice
    switch (choice) {
        case 1: 
            result = linearSearch(arr, n, key); 
            break;
        case 2: 
            result = binarySearch(arr, n, key); 
            break;
        case 3: 
            result = interpolationSearch(arr, n, key); 
            break;
        default: 
            cout << "Invalid choice!"; 
            return 0;
    }
    
    // Display result
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;
    
    return 0;
}