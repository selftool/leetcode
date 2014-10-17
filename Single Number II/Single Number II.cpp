// Single Number II 
/* Author��@Dasiy
��int�͵ĸ���Ԫ��������λ�ļӷ������Ȼ��ģ2����32λ������֮�󣬵õ���32λ����ֻ����һ���Ǹ�����32λ��
*/
#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
	int c[32];
	for (int i = 0; i < 32; ++i) {
		c[i] = 0;
	}
    for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 32; ++j) {  // Ϊint 32λ ÿһλ��ֵ
            c[j] += (A[i] >> j) & 1; // A[i]����32�Σ��õ�ÿһλ��Ӧ��ֵ����1���룬�õ���Ҫ�����һλ��
            c[j] = c[j] % 3;
		} // Ϊ�����ÿ��ֵ
    }
    // ���õ�c���Ƕ�������Ǹ�������Ӧ�Ķ������룬ֻ��ת��Ϊint������
    int result = 0;
    for(int i = 0; i < 32; ++i) {
        result |= (c[i] << i); // ��result��bit��ֵ��Ϊc[i]��λ��ֵ 
        // result = result * 2 + c[i]; // why error? 
    }
    
    return result;
}
    
    
int main() {
	int a[10] = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4};
	cout << singleNumber(a, 10) << endl;
	
	return 0;
}
