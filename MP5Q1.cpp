/* Hernandez, Juris Karylle M.*/
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - 1; j++) {
            comparisons++;
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swaps++;
            }
        }
    }
}

void selectionSort(vector<int>& v, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    for (int i = 0; i < v.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++) {
            comparisons++;
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(v[i], v[minIndex]);
            swaps++;
        }
    }
}

void insertionSort(vector<int>& v, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    for (int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            comparisons++;
            v[j + 1] = v[j];
            swaps++;
            j--;
        }
        comparisons++;
        v[j + 1] = key;
        swaps++;
    }
}

void merge(vector<int>& v, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[left + i];
    for (int i = 0; i < n2; i++) R[i] = v[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        swaps++;
        k++;
    }
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
        swaps++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
        swaps++;
    }
}

void mergeSort(vector<int>& v, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid, comparisons, swaps);
        mergeSort(v, mid + 1, right, comparisons, swaps);
        merge(v, left, mid, right, comparisons, swaps);
    }
}

void showVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    vector<int> v(num);
    cout << "Enter elements: ";
    for (int i = 0; i < num; i++) {
        cin >> v[i];
    }

    vector<int> v1 = v;
    int comparisons, swaps;
    cout << "\nBubble Sort: ";
    bubbleSort(v1, comparisons, swaps);
    showVector(v1);
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    vector<int> v2 = v;
    cout << "\nSelection Sort: ";
    selectionSort(v2, comparisons, swaps);
    showVector(v2);
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    vector<int> v3 = v;
    cout << "\nInsertion Sort: ";
    insertionSort(v3, comparisons, swaps);
    showVector(v3);
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    vector<int> v4 = v;
    cout << "\nMerge Sort: ";
    comparisons = swaps = 0;
    mergeSort(v4, 0, v4.size() - 1, comparisons, swaps);
    showVector(v4);
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}