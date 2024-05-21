#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stack {
    vector<int> elements;

    void push(int x) {
        elements.push_back(x);
    }

    bool pop(int x) {
        if (elements.empty() || elements.back() != x) {
            return false;
        }
        elements.pop_back();
        return true;
    }
};

struct Queue {
    vector<int> elements;

    void push(int x) {
        elements.push_back(x);
    }

    bool pop(int x) {
        if (elements.empty() || elements.front() != x) {
            return false;
        }
        elements.erase(elements.begin());
        return true;
    }
};

struct PriorityQueue {
    vector<int> elements;

    void push(int x) {
        elements.push_back(x);
        push_heap(elements.begin(), elements.end());
    }

    bool pop(int x) {
        if (elements.empty() || elements.front() != x) {
            return false;
        }
        pop_heap(elements.begin(), elements.end());
        elements.pop_back();
        return true;
    }
};

int main() {
    int n;
    while (cin >> n) {
        bool isStack = true, isQueue = true, isPriorityQueue = true;
        Stack stack;
        Queue queue;
        PriorityQueue priorityQueue;

        for (int i = 0; i < n; ++i) {
            int command, x;
            cin >> command;
            if (command == 1) {
                cin >> x;
                if (isStack) stack.push(x);
                if (isQueue) queue.push(x);
                if (isPriorityQueue) priorityQueue.push(x);
            } else if (command == 2) {
                cin >> x;
                if (isStack && !stack.pop(x)) isStack = false;
                if (isQueue && !queue.pop(x)) isQueue = false;
                if (isPriorityQueue && !priorityQueue.pop(x)) isPriorityQueue = false;
            }
        }

        if (isStack && !isQueue && !isPriorityQueue) {
            cout << "stack" << endl;
        } else if (!isStack && isQueue && !isPriorityQueue) {
            cout << "queue" << endl;
        } else if (!isStack && !isQueue && isPriorityQueue) {
            cout << "priority queue" << endl;
        } else if (!isStack && !isQueue && !isPriorityQueue) {
            cout << "impossible" << endl;
        } else {
            cout << "not sure" << endl;
        }
    }
    return 0;
}
