// Single Number
/*
����ģ2���������ֱ�Ӳ������^����˽����е�Ԫ��������������ʣ�µ��Ǹ�Ԫ�ؾ��ǽ���ˡ�����ָofferԭ�⣩ 
*/
#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
	if (0 == n) return 0;
	if (1 == n) return A[0];
	int ret = A[0];
	for (int i = 1; i < n; ++i) {
		ret ^= A[i];
	}
	
	return ret;
}

int main() {
	int a[10] = {1, 1, 2, 2, 3, 4, 4};
	cout << singleNumber(a, 7) << endl;
	
	return 0;
}
