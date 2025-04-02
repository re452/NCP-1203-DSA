#include <iostream>
#include <stack>
using namespace std;
stack<int> s;

void pushData(stack<int> s, int value) {
    s.push(value);
    cout << value << " has been pushed." << endl;
}

void popData(stack<int> s) {
    if (!s.empty()) {
     int value = s.top();
     cout << value << " has been popped." << endl;
     s.pop();
    }
    else {
     cout << "Stack is empty." << endl;
    }
}

void showTop(stack<int> s) {
    if (!s.empty()) {
     cout << "Top element is: " << s.top() << endl;
    }
    else {
     cout << "Stack is empty." << endl;
    }
}

void showSize(stack<int> s) {
     cout << "Size of stack is: " << s.size() << endl;
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
         pushData(s, value);
        }
     break;
     pushData(s, value);
     break;
    case 'B': case 'b':
     popData(s);
     break;
    case 'C': case 'c':
     showTop(s);
     break;
    case 'D': case 'd':
     showSize(s);
     break;
    case 'E': case 'e':
     cout << "Program has ended." << endl;
     return 0;
    default:
     cout << "Invalid choice, please try again!" << endl;
        }
    }
  return 0;
}
