#include <iostream>
#include <vector>

using namespace std;
/**
* ����������ʱ���� 
**/
/* 
int maxArea(vector<int> &height) {
	int size = height.size();
	int max = 0;
	for (int i = 0; i < size; i++ ) {
		for (int j = i+1; j < size; j++ ) {
			int area = ( j - i ) * ( height[i] < height[j] ? height[i] : height[j] );
			if (area > max ) {
				max = area;
			}
		}
	}
	return max;
}
*/
/**
* ����ͷ���м俿£��ͬʱ���º�ѡֵ�������������ʱ�����ȴ�  x, y�н�С�ı߿�ʼ������
* ������ͷ����������ɵ������ô����ʱ��ֻ�е����������Ǹ���ĸ߶ȴ��ڵ�ǰ�ĸ߶�ʱ���ſ���ʹ���������
* ����ʱ������������ѡ����ͷ�нϰ�����һ�㿪ʼ���� 
* �������ʵ���Ǹ��бƷ��ر��� 
**/ 
int maxArea(vector<int> &height) {
	int size = height.size();
	if (size == 0) return 0; 
	int left = 0;
	int right = size - 1;
	int max = (size-1) * (height[left] < height[right] ? height[left] : height[right]);
	while(left < right) {
		if(height[left] < height[right]) {
			int i = left + 1;
			while (height[i] < height[left]) {
				i++;
			}
			left = i;
			int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
			if (area > max) max = area; 
		}
		else {
			int i = right - 1;
			while(height[i] < height[right]) {
				i--;
			}
			right = i;
			int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
			if (area > max) max = area; 
		}
	}
	
	return max;
}

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	
	cout << maxArea(vec) << endl;
	
	return 0; 
}
