#include <bits/stdc++.h>
using namespace std;
#define show(v) for (auto i : v) cout << i << " "; cout << endl;

int stepCount = 0;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // cout << "Compare " << arr[j] << " and " << pivot << "\n";
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            // cout << "Swap " << arr[i] << " and " << arr[j] << "\n";
            // show(arr);
        }
    }
    // cout << "Swap " << arr[i + 1] << " and " << arr[high] << "\n";
    swap(&arr[i + 1], &arr[high]);

    // Print pivot and array after partition
    cout << "Pivot: " << pivot << "\n";
    cout << "Array after partition: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n\n";
    stepCount++;
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        stepCount++;
        int pi = partition(arr, low, high);
        stepCount++;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    ifstream file("input.txt");
    vector<int> arr;
    int x;
    while (file >> x) {
        arr.push_back(x);
    }
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Step count for " << arr.size() << " data to quick sort: " << stepCount << endl;
    // cout << "Sorted array: \n";
    // printArray(arr);
    return 0;
}