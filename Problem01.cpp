//Calculate the time complexity of an algorithm for finding the maximum and
minimum in an unsorted array
#include <iostream>
#include <climits>
using namespace std;


void findMinMax(int arr[], int n, int &min, int &max) {
    if (n == 0) return;

    min = INT_MAX;
    max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
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

    int min, max;
    findMinMax(arr, n, min, max);

    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;

    return 0;
}
