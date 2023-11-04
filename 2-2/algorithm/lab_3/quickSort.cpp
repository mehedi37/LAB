#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
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
    while (!file.eof()) {
        file >> x;
        arr.push_back(x);
    }
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted array(" << n << " elements) using quick sort is :" << endl;
    printArray(arr);
    return 0;
}