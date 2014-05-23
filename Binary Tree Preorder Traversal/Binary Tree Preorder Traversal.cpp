#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 
/*
������������ǵݹ鷽��������û�뵽һ�Ѿ͹��ˡ���
�㷨�Ƿ��������ϵ�����ǵݹ鷽������������
���Ǻ���ǵݹ����ò����һ���ĸ��Ӷȣ��� 
*/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
vector<int> preorderTraversal(TreeNode *root) 
{
    //if (root == NULL)
    //    return NULL;
    vector<int> result; 
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (p || !s.empty())
    {
        if (p)
        {
            result.push_back(p->val);
            s.push(p);
            p = p->left;
        }
        else 
        {
            p = s.top();
            //visit(p)���������ǵݹ�����Ļ���ǰ��ķ��ʲ������Ƿ�������� 
            s.pop();
            p = p->right; 
        }     
    }
    return result;
}

int main()
{
    vector<int> result;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;
    result = preorderTraversal(n1); 
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
