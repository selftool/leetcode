// Remove Duplicates from Sorted Array
/*
�����Ŀ���ð���������ݸı䣬����Ҫ����Ԫ�صĸ���
��˻���Ҫ�ı�A[ret++]��ֵ����leecode��Ӧ����Ҫ��ret�����в��ظ���Ԫ�ط���ǰ�������0->ret-1��λ���� 

��ĿҪ���ܿ����µ�����������������ôҪ����ԭ���飬Ҳ����˵Ԫ�鱻��������λ�ã���������������յĽ��
����ʹ��ret����Ǵ�ŵĽ�����±꣬ret�������Ǻ��������Ԫ�صĸ�����Ӧ�� 
*/
#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	if (0 == n) return 0;
	if (1 == n) return 1;
	int temp = A[0];
	int repeat = 0;
	int ret = 0; // ���ظ���Ԫ�ظ��� 
	// int ans = 0; // �ظ���Ԫ�ظ��� 
	for (int i = 1; i < n; ++i) {
		if (temp == A[i]) {
			if (0 == repeat) {
				A[ret] = temp; // ��Σ�յĲ��������ret�Ǵ�0��ʼ��ģ���i��1��ʼ�㣬�����ﲻ���д���Ϊֻ�������һ�� 
				++ret; // ��0��Ϊ1ʱ
			} 
			repeat = 1;
		}
		else {
			if (0 == repeat) {
				A[ret] = temp;
				++ret; // ���ֲ��ظ�Ԫ��ʱ 
			}
			temp = A[i];
			repeat = 0; 
		}
	}
	if (0 == repeat) {
		A[ret] = temp;
		++ret;
	}
	
	return ret;
}

int main() {
	int a[] = {1, 1, 2, 3, 3, 3, 4, 4, 5};
	
	cout << removeDuplicates(a, 9) << endl;
	
	return 0;
}
