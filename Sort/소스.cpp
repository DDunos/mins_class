#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];

class _sort {
public:
	int n, D_arr[10000], A_arr[10000], temp;
	void get_Arr() {
		for (int i = 0; i < n; i++) {
			cout << i + 1 << "��° �� : ";
			cin >> arr[i];
		}
	}
	void Descending() {
		copy(arr, arr + 10000, D_arr);
		cout << "�������� : ";
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (D_arr[i] < D_arr[j]) {
					temp = D_arr[i];
					D_arr[i] = D_arr[j];
					D_arr[j] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++) cout << D_arr[i] << " ";
		cout << endl;
	}
	void Ascending() {
		copy(arr, arr + 10000, A_arr);
		cout << "�������� : ";
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (A_arr[i] > A_arr[j]) {
					temp = A_arr[i];
					A_arr[i] = A_arr[j];
					A_arr[j] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++) cout << A_arr[i] << " ";
		cout << endl << endl;
	}
	_sort(int a) { n = a; }
};

int main() {
	int n;
	cout << "�迭 ũ�� : ";
	cin >> n;
	_sort a = _sort(n);
	a.get_Arr();
	int ch = -1;
	while (ch) {
		cout << "1: �������� ����"<<endl;
		cout << "2: �������� ����"<<endl;
		cin >> ch;
		if (ch == 1)
			a.Descending();
		else if (ch == 2)
			a.Ascending();
		else
			cout << "�� �� �Է��ϼ̽��ϴ�.";
	}
}