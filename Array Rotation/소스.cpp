#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000][1000], temp_arr[1000][1000];

class rotation {
public:
	int n, h;
	void right() {
		for (int i = 0; i < h; i++) {
			for (int j = i; j < n - i - 1; j++) {
				arr[i][j + 1] = temp_arr[i][j];
			}
		}
		for (int i = h; i < n; i++) {
			for (int j = i; j > n - i - 1; j--) {
				arr[i][j - 1] = temp_arr[i][j];
			}
		}
		for (int j = 0; j < h; j++) {
			for (int i = n - j - 1; i > j; i--) {
				arr[i - 1][j] = temp_arr[i][j];
			}
		}
		for (int j = h; j < n; j++) {
			for (int i = n - j - 1; i < j; i++) {
				arr[i + 1][j] = temp_arr[i][j];
			}
		}
		copy(&arr[0][0], &arr[0][0] + 1000 * 1000, &temp_arr[0][0]);
	}
	void left() {
		for (int i = 0; i < h; i++) {
			for (int j = n - i - 1; j > i; j--) {
				arr[i][j - 1] = temp_arr[i][j];
			}
		}
		for (int i = h; i < n; i++) {
			for (int j = n - i - 1; j < i; j++) {
				arr[i][j + 1] = temp_arr[i][j];
			}
		}
		for (int j = 0; j < h; j++) {
			for (int i = j; i < n - j - 1; i++) {
				arr[i + 1][j] = temp_arr[i][j];
			}
		}
		for (int j = h; j < n; j++) {
			for (int i = j; i > n - j - 1; i--) {
				arr[i - 1][j] = temp_arr[i][j];
			}
		}
		copy(&arr[0][0], &arr[0][0] + 1000 * 1000, &temp_arr[0][0]);
	}
	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%7d ", arr[i][j]);
			cout << endl;
		}
	}
	rotation(int a, int b) { n = a, h = b; }
};
int main() {
	int n, h, r, l, k = 1;
	cout << "배열의 크기 : ";
	cin >> n;
	if (n % 2 == 0)
		h = n / 2;
	else
		h = (n + 1) / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = k;
			k++;
		}
	}
	copy(&arr[0][0], &arr[0][0] + 1000 * 1000, &temp_arr[0][0]);
	rotation a = rotation(n, h);
	a.print();
	printf("\n");
	cout << "오른쪽 회전 수 : ";
	cin >> r;
	cout << "왼쪽 회전 수 : ";
	cin >> l;
	for (int i = 0; i < r; i++)
		a.right();
	for (int i = 0; i < l; i++)
		a.left();
	a.print();
}