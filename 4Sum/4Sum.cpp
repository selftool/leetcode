// 4Sum
/*
��3Sumһ������������ȷ������Ԫ�أ�ת����Ϊ2Sum���⣬�бƷ�������ؼ�������ȥ�� 
������������ȷ������Ԫ�ؾ���ҪO(n*n)�ĸ��Ӷȣ���������˼·�����帴�Ӷ���O(n*n*n) 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
	int size = num.size();
	vector<vector<int> > ret;
	if (size < 4) return ret;
	sort(num.begin(), num.end());
	for (int i = 0; i < size; ++i) {
		if (i != 0 && num[i] == num[i-1]) continue; // ��һ��ȥ�� 
		for (int j = i + 1; j < size; ++j) {
			if (j != i+1 && num[j] == num[j-1]) continue; // �ڶ���ȥ��
			int left  = j + 1;
			int right = size - 1;
			while (left < right) {
				int sum = num[i] + num[j] + num[left] + num[right]; 
				if (target == sum) {
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[left]);
					temp.push_back(num[right]);
					// ������ȥ�أ���������ȥ��֮���ҵ�����Ԫ��ֻ�����Ǻ�ret�е����һ����Ԫ���ظ� 
					if (ret.size() == 0 || ret[ret.size()-1] != temp) {  
						ret.push_back(temp);
					}
					++left;
					--right; 
				}
				else if (sum > target) {
					--right;
				} 
				else {
					++left;
				}
			}  
			
		}
	}  
	
	return ret;
} 

int main () {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(-2);
	vec.push_back(2);
	
	vector<vector<int> > ret = fourSum(vec, 0);
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << "\t"; 
		}
		cout << endl;
	}
	
	return 0;
}
