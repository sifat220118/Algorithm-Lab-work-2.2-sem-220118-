//Finding Minimum and Maximum Using Divide-and-Conquer and Normal
#include <iostream>
#include <climits>
using namespace std;


void findMinMaxNormal(int arr[], int n, int &min, int &max) {
    min = INT_MAX;
    max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

void findMinMaxDAC(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {
        min = max = arr[low];
        return;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        } else {
            min = arr[high];
            max = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    int min1, max1, min2, max2;
    findMinMaxDAC(arr, low, mid, min1, max1);
    findMinMaxDAC(arr, mid + 1, high, min2, max2);
    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
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
    int choice;
    cout << "Choose method:\n";
    cout << "1. Normal Method\n";
    cout << "2. Divide and Conquer Method\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    int min, max;

    if (choice == 1) {
        findMinMaxNormal(arr, n, min, max);
        cout << "Normal Method - Min: " << min << ", Max: " << max << endl;
    } else if (choice == 2) {
        findMinMaxDAC(arr, 0, n - 1, min, max);
        cout << "Divide and Conquer Method - Min: " << min << ", Max: " << max << endl;
    } else {
        cout << "Invalid choice! Please enter 1 or 2." << endl;
    }

    return 0;
}
