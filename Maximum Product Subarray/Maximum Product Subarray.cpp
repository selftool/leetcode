// Maximum Product Subarray
// ��ʵ�����������������ģ��˻�����
// Ӧ�����������������֮����һ�±Ƚϣ����Ӷ�̬�滮����ѧ�Ƶ����̡�	 
#include <iostream>
#include <algorithm>
#include <cmath> 
 
using namespace std;

// ����ʵ��:��
// 1.ע�⴦������Ԫ��ȫ��Ϊ���������
// 2.ע����������������֮�Ͳ�ͬ����������֮���ǿ���Ϊ������ 
// ˼·����̬�滮��positive��negative�ֱ𱣴��������ֵ��������Сֵ������ֵ���; 
// ÿһ�ָ��µ�ʱ�򣬵�a[i]Ϊ������>=0��ʱ��positive=positive*a[i], negative=negative*a[i];
// ����positive=negative*a[i], nagative=postive*a[i](�˴���positiveû�и��µ�positive);
int maxProduct(int A[], int n) {
	int pos = 1;
	int neg = 1;
	int max_pro = INT_MIN;
	for (int i = 0;  i < n; ++i) {
		if (A[i] >= 0) {
			pos = pos * A[i];
			neg = neg * A[i];
		}
		else {
			int temp = pos;
			pos = neg * A[i];
			neg = temp * A[i];
		}
		max_pro = max(max_pro, pos);
		if (pos < 1) pos = 1; // �˴�Ӧ����pos == 0,��posΪ0ʱ��Ӧ�ý�pos������Ϊ1 
		if (neg > -1) neg = 1; // ����Ҳ����neg == 0,���Ǽ��������������doubleʱ����Ӧ����1.0f�ˡ� 
	}
	
	return max_pro;
}

int main() {
	int a[4] = {2, 3, -2, 4};
	cout << maxProduct(a, 4);
	
	return 0;
}
