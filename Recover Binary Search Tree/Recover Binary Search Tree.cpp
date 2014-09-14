#include <iostream>

using namespace std;

// �������������ؽ�,��Ŀ��˵��ֻ�������ڵ���Ҫ����������ô����������ҳ��������ڵ��� 
// ˼·��ǰ��/����/����������������Ƚϵ�ǰ�ڵ㣬�����ӽڵ㣬���ӽڵ��ֵ
// ����߳��ִ���ʱ��left=1;�ұ߳���ʱ��right=1��Ȼ����left��right��Ϊ1���򽻻������ӽ��
// ���򣬵�left=1ʱ��������ǰ�ڵ�����ӽ�� ����right=1ʱ��������ǰ�ڵ�����ӽڵ� 
// �Ҳ��õ���ǰ���������
// ****������������̣�˳����߼�˼ά��ʽû�а취����ܶ�����**** 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversalTree(TreeNode *root) {
	if (NULL == root) return;
	int left = 0, right = 0;
	if (NULL != root->left) {
		if (root->left->val > root->val) {
			left = 1;
		}
	}
	if (NULL != root->right) {
		if (root->right->val < root->val) {
			right = 1;
		}
	}
	if (left == 1 && right == 1) {
		int temp = root->left->val;
		root->left->val = root->right->val;
		root->right->val = temp;
	}
	if (left == 1 && right != 1) {
		int temp = root->val;
		root->val = root->left->val;
		root->left->val = temp;
	}
	if (left != 1 && right == 1) {
		int temp = root->val;
		root->val = root->right->val;
		root->right->val = temp;
	}
	if (root->left != NULL)
		traversalTree(root->left);
	if (root->right != NULL)
		traversalTree(root->right);
}

void recoverTree(TreeNode *root) {
	if (NULL == root) return;
	traversalTree(root);
}
// ���������Ǵ��
 
// �����������ӡ 
void printTree(TreeNode *root) {
	if (NULL != root) {
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right); 
	}
}
// ��׼answer������������������ʱ������������ǵ����� 
// ��ʾ�� 
// �ȿ�һ���������У�1 2 3 4 5 6 7.
// ����4��6��1 2 3 6 5 4 7
// ע�⣬6�ǵ�һ�����ں�һ��Ԫ�صģ�6 > 5�� 5 > 4����4�����һ��С��ǰһ��Ԫ�صģ�5 < 6��4 < 5����
TreeNode *node1, *node2;  
TreeNode *pre;  
      
void traverse(TreeNode *root) {  
    if (root == NULL) {  
        return;  
    }      
    traverse(root->left);  
    if (pre != NULL && pre->val > root->val) {  
        node2 = root;  
        if (node1 == NULL) {  
            node1 = pre;  
        }  
    }  
    pre = root;  
    traverse(root->right);  
}
void recoverTree2(TreeNode *root) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    node1 = node2 = NULL;  
    pre = NULL;  
    traverse(root);          
    node1->val ^= node2->val;  
    node2->val ^= node1->val;  
    node1->val ^= node2->val;  
} 
//

int main() {
	// �˹��潨�������� 
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t4->right = t5;
	printTree(t1);
	cout << endl;
	// ��������Ľڵ㣬�ؽ�����������
	recoverTree2(t1);
	printTree(t1);
	
	return 0; 
} 
