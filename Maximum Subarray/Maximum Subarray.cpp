// Maximum Subarray
/*
�����������������⣬��̬�滮˼�룬�ҵ����ƹ�ʽ
ע��ȫ��Ϊ��������� 
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int maxSubArray(int A[], int n) {
	int max_sum = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n ; ++i) {
		sum += A[i];
		if (sum < 0) {
			sum = 0; 
			max_sum = max(max_sum, A[i]); // ����ȫ��Ԫ�ض�Ϊ��������� 
		}
		else {
			max_sum = max(max_sum, sum);
		}
		
	}
	
	return max_sum;
}

int main() {
	int n = 9;
	int a[] =  {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(a, n);
	
	return 0;
}
