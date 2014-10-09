// 3Sum Closest 
/*
˼·��3Sum����һ�����գ�������ȷ��һ�����֣�
Ȼ���ڼбƹ����в��ϵظ���min_offset��������С�ľ��룩������sign����offset�������� 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &num, int target) {
	int ret;
	int size = num.size();
	if (3 > num.size()) return ret;
	sort(num.begin(), num.end());
	int min_offset = INT_MAX;
	int sign;
	for (int i = 0; i < size; ++i) {
		int left = i + 1;
		int right = size - 1;
		while (left < right) {
			if (num[left] + num[right] + num[i] == target) {
				return target;
			}
			else if (num[left] + num[right] + num[i] > target) {
				int offset = num[left] + num[right] + num[i] - target;
				if (offset < min_offset) {
					min_offset = offset;
					sign = 1;
				} 
				--right; 
			}
			else {
				int offset = 0 - (num[left] + num[right] + num[i] - target);
				if (offset < min_offset) {
					min_offset = offset;
					sign = -1;
				}
				++left;
			}
		}
	}
	ret = target + sign*min_offset;
	
	return ret;
}

int main() {
	vector<int> vec; 
	vec.push_back(-1);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(-4);
	
	int target = 1;
	cout << threeSumClosest(vec, target);
	
	return 0;
}
