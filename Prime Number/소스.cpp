#include <iostream>
#include <cmath>

using namespace std;

int check[10001] = { false };

class P_Number {
public:
	int n;
	void isPNum() {
		check[0] = check[1] = true;
		for (int i = 2; i < sqrt(n); i++) {
			if (check[i] == false) {
				for (int j = i + i; j <= n; j += i) {
					check[j] = true;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) printf("%d ", i);
		}
	}
	P_Number(int a) { n = a; }
};
int main() {
	int n;
	cout << "�Ҽ� ���ϴ� ���� : ";
	cin >> n;
	P_Number a = P_Number(n);
	a.isPNum();
	return 0;
}