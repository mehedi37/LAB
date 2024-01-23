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
    int pivot = arr[low];
    int i = low;
    int j = high;
    int pv = 1;
    cout << "Pivot: " << pivot << "\n";
    while (i < j) {
        cout << "For pivot " << pv++ << ": \n";
        while (arr[i] <= pivot) {
            i++;
            stepCount++;
        }
        while (arr[j] > pivot) {
            j--;
            stepCount++;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
    }
    swap(&arr[low], &arr[j]);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    stepCount++;
    return j;
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

// int main() {
//     vector<int> arr;
//     int x;
//     while (cin >> x) {
//         arr.push_back(x);
//     }
//     int n = arr.size();
//     quickSort(arr, 0, n - 1);
//     cout << "Step count for " << arr.size() << " data to quick sort: " << stepCount << endl;
//     return 0;
// }