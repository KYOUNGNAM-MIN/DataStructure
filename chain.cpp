#include <iostream>
#include "chain.h"
using namespace std;

void josephusIteration(int n, int k) {
	int a = 1;
	for (int i = 1; i <= n; i++) {
		a = (a + k - 1) % i + 1;
		cout << a << endl;
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	Chain a(n, m, k);
	josephusIteration(n, k);
	//a.Delete();

	return 0;
}
