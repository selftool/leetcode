/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
/*
˼·�ܼ򵥣����ǹ�ϣ�����������Ԫ��ȫ��ӳ�䵽hash��֮��
�������飬����Ԫ���������ߵ������Ƿ���ڣ�������˵����ǰ����������������ߺ��ұߵ�leftLen, rightLen
ÿ��ѭ��ֹͣʱ���ж�һ������������еĳ����Ƿ����ǰһ�����еĳ��ȣ����������maxlen 
*/

#include <iostream>
#include <vector>
//#include <unordered_set>  // dev-c����ͷ�ļ�������ʱ��set���棬����set�ĸ��Ӷ���log����ģ���unordered_set�ڲ�ʵ����ɢ�б� 
#include <set>
using namespace std; 

int longestConsecutive(vector<int> &num) {
	//unordered_set<int> flag;  // ֻ��ʹ��unordered_set����ʵ��o(n)���Ӷ� ��leetcode����ʾ����60ms 
	set<int> flag; // ʵ�������log(n)�ĸ��Ӷ���oj��Ҳ�ܹ���104ms������Ҳ˵���˼�ʹ��ʹ��������Ҳ���Թ��� 
	// ��ʼ����ϣ���������Ԫ�ز����ϣ�� 
	for (int i = 0; i < num.size(); i++){
		flag.insert(num[i]);
	}
	int maxLen = 0;
	for (int i = 0; i < num.size(); i++) {
		int leftLen = 0;
		int currentVal = num[i] - 1;
		while ( flag.find(currentVal) != flag.end() ) {
			leftLen += 1;
			flag.erase(currentVal); // ��һ���ǳ��ؼ������Ż�ʱ�临�ӶȵĹؼ��� 
			currentVal --;
		}
		
		int rightLen = 0;
		currentVal = num[i] + 1;
		while( flag.find(currentVal) != flag.end() ) {
			rightLen += 1;
			flag.erase(currentVal); // ��һ���ǳ��ؼ������Ż�ʱ�临�ӶȵĹؼ��� 
			currentVal ++;
		} 
		
		flag.erase(num[i]);  // ��һ���ǳ��ؼ������Ż�ʱ�临�ӶȵĹؼ��� 
		if ( (leftLen + rightLen + 1) > maxLen) {
			maxLen = leftLen + rightLen + 1 ; 
		}
	} 
	
	return maxLen;
}

int main()
{
	vector<int> vector;
	vector.push_back(100);
	vector.push_back(4);
	vector.push_back(200);
	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(2);
	
	cout << longestConsecutive(vector) << endl;  
	
	return 0;
	
}
