#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
 stack<int>s_num;
 queue<int>q_num;
  int num;

int main() {
    cout << "Enter the size of array: ";
    cin >> num;
    vector<int> v(num);

    cout << "[stack] Enter a number: ";
        for (int i = 0; i < num; i++) {
            cin >> v[i];
            s_num.push(v[i]);
    }
    cout << "[queue] Enter a number: ";
        for (int i = 0; i < num; i++) {
            cin >> v[i];
            q_num.push(v[i]);
    }
    cout << "Stack: ";
    while (!s_num.empty()) {
        cout << s_num.top() << " ";
        s_num.pop();
    }
    cout << endl;
    cout << "Queue: ";
    while (!q_num.empty()) {
        cout << q_num.front() << " ";
        q_num.pop();
    }
    cout << endl;
}