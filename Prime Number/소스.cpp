#include <iostream>
#include <cmath>

using namespace std;

class P_Number {
public:
	int n, check[10001] = { false };
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
	cout << "소수 구하는 범위 : ";
	cin >> n;
	P_Number a = P_Number(n);
	a.isPNum();
	return 0;
}