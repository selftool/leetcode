// 3Sum 
/*
������2Sum�ļб�˼�룬�ȶ���һ��Ԫ��val�������ת����������������Ԫ��֮��Ϊtarget=0-val��
�Ϳ��Բ��üбƵ�˼�����ˡ�
ʵ�֣�
1. ��ԭ�����������
2. �������������飬�ȶ��µ�i��Ԫ�ص�ֵa[i]��Ȼ����ʣ�µ�Ԫ���в��üбƷ����ҵ�����Ԫ�صĺ�Ϊ0-a[i]�� 
�������ʱ����a[i]������left��mid��right����Ԫ���е�leftԪ�أ���ômid��right��ȡֵ��ΧΪ��i+1��n-1�� 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > ret;
	if (3 > num.size()) return ret;
	sort(num.begin(), num.end());
	int size = num.size();
	vector<int> temp; 
	int current = num[0]; 
	for (int i = 0; i < size; ++i) {
		// ��һ��ȥ�أ�����Ԫ�鿪ͷ��Ԫ��ȥ�� 
		// ��ÿһ��Ԫ�ؿ�ͷ����Ԫ�飬�����Ԫ�ص�һ����Ϊ��Ԫ���left����ʱ�����Ѿ�ȫ���ҳ����ˡ� 
		if (i != 0 && num[i] == current) {  
			continue;
		}
		current = num[i];
		int target = 0 - num[i];
		int mid = i + 1;
		int right = size - 1;
		while (mid < right) { // O(n*n)�ĸ��Ӷ� 
			if (num[mid] + num[right] == target) { // �ҵ�һ����Ԫ��
				temp.push_back(num[i]);
				temp.push_back(num[mid]);
				temp.push_back(num[right]);
				// �ڶ���ȥ�أ�����ĳһ��Ԫ�ؿ�ͷ����Ԫ���У�������ֵ���Ԫ�鲻���ظ����� 
				// ��Ԫ��ret���Ͻ�������,��Ϊ���Ѿ��ź���ģ�������ϵ����ret��Ԫ��Ҳ���ź���� 
				// ����ֻҪ��ret���һ��Ԫ�رȽϼ��ɡ� 
				if (ret.size() == 0 || ret[ret.size()-1] != temp) 
					ret.push_back(temp);
				temp.clear();
				--right;
				++mid;
			}
			else if (num[mid] + num[right] > target) {
				--right;
			}
			else {
				++mid;
			}
		}
	} 
	
	return ret;
}

int main () {
	vector<int> vec;
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(-1);
	vec.push_back(-4);
	vec.push_back(-1);
	
	vector<vector<int> > ret = threeSum(vec);
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << "\t"; 
		}
		cout << endl;
	}
	
	return 0;
}
