//Binary Search Using Divide-and-Conquer Method
#include <iostream>
using namespace std;


int binarySearchDAC(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;


    if (arr[mid] == target) {
        return mid;
    }


    if (target < arr[mid]) {
        return binarySearchDAC(arr, low, mid - 1, target);
    } else {
        return binarySearchDAC(arr, mid + 1, high, target);
    }
}


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;
    int result = binarySearchDAC(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index " << result << "." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
