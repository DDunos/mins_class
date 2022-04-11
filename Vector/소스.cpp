#include<iostream>
using namespace std;

class Vector {
    int top;
    int* array;

public:
    Vector(int n);
    void push_back(int value);
    void pop_back();
    void size();
};

Vector::Vector(int n) {
    top = 0;
    array = new int[n];
}

void Vector::push_back(int value) {
    int n = _msize(array);

    if (top == n) {
        cout << "error" << endl;
    }
    else {
        array[top++] = value;
    }
}

void Vector::pop_back() {
    if (top == 0) {
        cout << "error" << endl;
    }
    else {
        cout << array[top - 1] << " ";
        top--;
    }
}

void Vector::size() {
    cout << endl << "������� ����� array�� �� ����: " << top;
}

int main() {
    Vector a = Vector(100);
    int n, p;

    cout << "�迭�� ũ��: ";
    cin >> n;
    int* v = new int[n];

    cout << "value ��: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a.push_back(v[i]);
    }

    cout << "pop Ƚ��: ";
    cin >> p;
    for (int i = 0; i < p; i++) {
        a.pop_back();
    }

    a.size();
}