/* Hernandez, Juris Karylle M. */
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

void pushData(queue<int>& q, int value) {
    q.push(value);
    cout << value << " has been pushed." << endl;
}

void popData(queue<int>& q) {
    if (!q.empty()) {
     int value = q.front();
     cout << value << " has been popped." << endl;
     q.pop();
    }
    else {
     cout << "Queue is empty." << endl;
    }
}

void showFront(const queue<int>& q) {
    if (!q.empty()) {
     cout << "Front element is: " << q.front() << endl;
    }
    else {
     cout << "Queue is empty." << endl;
    }
}

void showSize(const queue<int>& q) {
    cout << "Size of queue is: " << q.size() << endl;
}

int main() {
    int value;
    char choice;
    while (true) {
     cout << "[A] Push Data\n[B] Pop Data\n[C] Show Top\n[D] Show Size\n[E] Quit" << endl;
     cout << "Enter Choice: ";
     cin >> choice;
    switch (choice) {
     case 'A': case 'a':
     int x;
      cout << "Enter a number of elements to push: ";
      cin >> x;
        for (int i = 0; i < x; i++) {
            cout << "Enter number to push: ";
            cin >> value;
            pushData(q, value);
        }
        break;
     case 'B': case 'b':
        popData(q);
        break;
     case 'C': case 'c':
        showFront(q);
        break;
     case 'D': case 'd':
        showSize(q);
        break;
     case 'E': case 'e':
        cout << "Program has ended." << endl;
        return 0;
        break;
     default:
        cout << "Invalid choice, please try again!" << endl;
        break;
       }
    }
    return 0;
}
