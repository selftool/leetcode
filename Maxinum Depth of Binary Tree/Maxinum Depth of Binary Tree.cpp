// Maxinum Depth of Binary Tree 
#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
** 1������С��Ȳ�һ������С��Ȳ���ֱ�ӵݹ�Ƚ�������������������С����ȣ���Ϊ��һ������Ϊ��ʱ�����صĴ�С��0 
** ��Ϊmin����ȡ���Ļ����Ǹ�null��������ȣ���+1���ء�
** 2�������ǵ�Ҷ�ӽڵ㶨�岻�������ģ�Ӧ�ðѷ�null���Ǹ����������ȡ��������+1��
** �����Ͳ��ÿ�������ˣ���Ϊnull��������Ȳ��ᱻȡ����������ֱ�Ӳ��÷ֳ�һ��root�����������ĸ��ַ�null����� 
*/
int maxDepth(TreeNode *root) {
	if (NULL == root) return 0;
	if (NULL == root->left && NULL == root->right) {
		return 1;
	} 
	else {
		return max(maxDepth(root->left), maxDepth(root->right))+1;
	}
}
