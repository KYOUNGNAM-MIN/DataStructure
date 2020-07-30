//이진탐색(Binary Search)

//이진탐색은 이미 정렬이 된 자료를 대상으로 해야 한다.

#include <iostream>
#include <time.h>
using namespace std;

int BS(int* a, const int b, const int n) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (b > a[m]) {
			l = m + 1;
		}
		else if (b<a[m]) {
			r = m - 1;
		}
		else {
			return m;
		}
	}
}

int main() {
	clock_t start = clock();

	int x[14] = { 3,7,8,9,12,16,18,19,20,26,30,31,44,50 };
	int b;
	for (int i = 0; i < 14; i++) {
		cout << x[i] << endl;
	}
	cout << "다음 중 찾고 싶은 값을 골라주세요" << endl;

	cin >> b;

	cout << "찾는 값은 0~13번 중에 " << BS(x, b, 14) << "번째 있습니다." << endl;
	
	start = clock() - start;
	cout << start << "    " << ((double)(start)) / CLOCKS_PER_SEC << endl;
	return 0;
}