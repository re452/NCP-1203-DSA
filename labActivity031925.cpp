#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void printArray(const vector<int>& v) {
    cout << "Sorted Array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int linearSearch(const vector<int>& v, int target, int& ctr) {
    ctr = 0;
    for (int i = 0; i < v.size(); i++) {
        ctr++;
        if (v[i] == target) {
        return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& v, int target, int& ctr) {
    ctr = 0;
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        ctr++;
        int mid = left + (right - left) / 2;

        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int jumpSearch(const vector<int>& v, int x, int& ctr) {
    ctr = 0;
    int n = v.size();
    int step = sqrt(n);
    int prev = 0;

    while (v[min(step, n) - 1] < x) {
        ctr++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        ctr++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int interpolationSearch(const vector<int>& v, int key, int& ctr) {
    ctr = 0;
    int low = 0;
    int high = v.size() - 1;

    while (low <= high && key >= v[low] && key <= v[high]) {
        ctr++;
        if (low == high) {
            if (v[low] == key) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (v[high] - v[low]) * (key - v[low]));

        if (v[pos] == key) {
            return pos;
        }

        if (v[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int num;
    cout << "Enter the size of array: ";
    cin >> num;
    vector<int> v(num);
    cout << "Enter elements: ";
    for (int i = 0; i < num; i++) {
        cin >> v[i];
    }
    
    int target;
    cout << "Which element would you like to search for?:  ";
    cin >> target;
    int ctr;

    sort(v.begin(), v.end());
    printArray(v);
    cout << "\nLinear Search: ";
    int linearResult = linearSearch(v, target, ctr);
    if (linearResult == -1) {
        cout << "Element not found." << endl;
    }
    else {
        cout << linearResult << "\nTimes the algorithm performed: " << ctr << endl;
    }

    cout << "Binary Search: ";
    int binaryResult = binarySearch(v, target, ctr);
    if (binaryResult == -1) {
        cout << "Element not found." << endl;
    }
    else {
        cout << "Binary Search: ";
        cout << binaryResult << "\nTimes the algorithm performed: " << ctr << endl;
    }

    cout << "Jump Search: ";
    int jumpResult = jumpSearch(v, target, ctr);
    if (jumpResult == -1) {
        cout << "Element not found." << endl;
    }
    else {
        cout << jumpResult << "\nTimes the algorithm performed: " << ctr << endl;
    }

    cout << "Interpolation Search: ";
    int interpolationResult = interpolationSearch(v, target, ctr);
    if (interpolationResult == -1) {
        cout << "Element not found." << endl;
    }
    else {
        cout << interpolationResult << "\nTimes the algorithm performed: " << ctr << endl;
    }

    return 0;
}