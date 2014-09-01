/*
* Longest Valid Parentheses �����ЧԲ���� 
* 1����ʼ��Ϊ˼·�ܼ򵥣����Ǹ�����ƥ������⣬һ��ջ����ʵ�֡� 
* 2����������()(()Ҫ�����2������4�����Ҫ�����ϸ���������Ž������ţ����ܹ��𿪣������������ԭ����ջ�����Ǹ����ϸ�
* �޸��Ժ�ֱ�ӱ����Ϳ����ˣ�����Ҫջ��pre��current�Ƚϣ�Ϊһ������ʱ��len+2 
* 3�����ǲ��ԣ�����()(())Ҫ���������Ϊ6��������4����Ҫ��ϸ����һ�¡��� ����д���˵ڶ����������left==right���� 
* 4�����ɲ��ԣ�������������£�����⻹��Ҫ��ջ����������Ҫ����ջ�����á� 
*/ 

/*
int longestValidParentheses(string s) {
	stack<char> stack; 
	int maxLen = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			stack.push(s[i]);
		}
		else
		{
			if (!stack.empty() && stack.top() == '(') {
				maxLen += 2;
				stack.pop();
			}
		}
	} 
	return maxLen;
}*/
/*
int longestValidParentheses(string s) {
	int maxLen = 0;
	int len = s.length();
	int left = 0;
	int right = 0; 
	for (int i = 0; i < len-1; i++) {
		if (s[i]=='(') {
			if (s[i+1] == ')') {
				if (left == 0) {
					maxLen += 2;
					i++;  // �������ŵ��������ţ��Ҳ���һ�������������� 
				} 
			}
			else 
			{
				left += 1; // �������������ŵ����� 
			}
		} 
		else
		{
			if (s[i+1]== '(') {
				// Ĭ�ϲ����� 
			}
			else
			{
				right += 1; // �������������ŵĴ��� 
			}
		} 
	} 
	//cout << "  left: " << left << endl;
	//cout << " right: " << right << endl;
	//cout << "maxLen: " << maxLen << endl;
	if (left != 0) {
		if (left == right) {
			maxLen = maxLen + (left+1)*2;
		}
		else
		{
			maxLen = 2*( (right < left ? right : left) + 1 ) ;
		}
	}
	return maxLen;
}*/ 

/* ���⣺ 
** ˼·һ��һ������������ƥ�䵽�����ţ�Ȼ���ҳ��������������ı���ǵ��±꣬���Ӷ�o(n)�� 
** ˼·����һ��ջ����¼ʧ��ʱ�������ŵ�λ�ã���ƥ��ʱ����ֱ�Ӵ�ʧ��������ŵ���һ���ַ���ʼ�㳤�ȡ� 
** ˼·����һά��̬�滮˼�룬length[]���顣 http://blog.csdn.net/pickless/article/details/9190961
** ���䣺����Ҫ����ӡ��ʼǣ���̬�滮̫��Ҫ�ˣ� 
*/ 
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
	vector<int> flag(s.length(), 0);
	stack<int> stack;
	int maxLen = 0;
	for (int i = 0; i < s.length(); i++) {
		if(s[i] == '('){
			stack.push(i);
		}
		else
		{
			if(!stack.empty()) {
				flag[stack.top()] = 1;
				flag[i] = 1;
				stack.pop();
			}
		}
	}
	
	int left = 0;
	int right = 0;
	for (int i = 0; i < flag.size(); i++) {
		if(flag[i] == 1)
		{
			left = i;
			while (i < flag.size() && flag[i] == 1 ){
				i++;
			}
			right = i-1;
			if (right-left+1 > maxLen) {
				maxLen = right-left+1;
			}
		}
	}
	
	
	return maxLen;
} 

int main(){
	//string s = "()(())";
	string s = "(()"; // "(()()"���ǲ��ԡ����������е�˼·ȫ�������ˡ��� 
	cout << longestValidParentheses(s) << endl;
	
	return 0;
}
