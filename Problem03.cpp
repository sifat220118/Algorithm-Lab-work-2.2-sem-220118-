#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;


int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}


int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, target, choice;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    cout << "Press 1 for Linear Search, 0 for Binary Search: ";
    cin >> choice;

    int result = -1;

    auto start = chrono::high_resolution_clock::now();

    if (choice == 1) {

        result = linearSearch(arr, n, target);
    } else if (choice == 0) {
        sort(arr, arr + n);
        result = binarySearch(arr, n, target);
    } else {
        cout << "Invalid choice!";
        return 0;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;


    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;


    cout << "Time taken: " << elapsed.count() << " seconds" << endl;

    return 0;
}

