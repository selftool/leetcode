#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
* ��ȡ����Ҷ�ӽڵ����ȣ��ҵ���Сֵ 
* Ҷ�ӽڵ�����жϣ����κ�һ����ǰ��root���ԣ������ӽڵ㶼Ϊ��ʱ�����Ǹ�Ҷ�ӽڵ㡣
* �����ӽڵ����κ�һ��ʱ��˵����root������Ҷ�ӽڵ㡣��Ҫ�ݹ鴦������ 
**/
int minDepth(TreeNode *root) {
	if (NULL == root) return 0;
	if (NULL == root->left && NULL == root->right) {
		return 1;
	}
	else if (NULL == root->left && NULL != root->right) {
		return minDepth(root->right)+1;
	}
	else if (NULL != root->left && NULL == root->right) {
		return minDepth(root->left)+1; 
	}
	else {
		return min(minDepth(root->left), minDepth(root->right))+1;
	}
}

int main() {
	// �˹��潨�������� 
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	t1->left = t2;
	t1->right = t5;
	t2->left = t3;
	t2->right = t4;
	t5->right = t6;
	
	cout << minDepth(t1) << endl; 
	
	return 0; 
} 
