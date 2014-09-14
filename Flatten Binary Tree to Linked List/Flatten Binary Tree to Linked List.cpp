#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *tail;

// ����ÿ���ڵ���Һ���ָ��(ԭ��)�����������һ���ڵ� 
void traverse(TreeNode *root) {
	if (NULL == root) return;
	TreeNode* left = root->left;  
    TreeNode* right = root->right;  
	if (NULL == tail) {
		tail = root;
	}
	else {
		tail->right = root;
		tail->left = NULL;
		tail = root;
	}
	traverse(left);
	traverse(right);	
} 

// ˼·��Ӧ�������������ǰ�ڵ�����ӽ����Ϊ���ӽڵ㣬���ӽڵ���Ϊ���ӽ������ӽڵ� 
void flatten(TreeNode *root) {
	if (NULL == root) return;
	traverse(root);
}


/* �ǵݹ鷨���ҵ������������½ǵĽڵ㣬�ýڵ����������Ϊroot->right��Ȼ���root��������Ϊroot->left 
void flatten(TreeNode *root) {  
        if(root == NULL) return;  
    while(root){  
        if(root->left){  
            TreeNode *pre = root->left;  
            while(pre->right)  
                pre = pre->right;  
            pre->right = root->right;  
            root->right = root->left;  
            root->left = NULL;  
        }  
        root = root->right;  
    }  
    }
*/
// �����������ӡ 
void printTree(TreeNode *root) {
	if (NULL != root) {
		cout << root->val << " ";
		printTree(root->left);
		printTree(root->right); 
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
	printTree(t1);
	cout << endl;
	flatten(t1);
	printTree(t1);
	
	return 0; 
} 


