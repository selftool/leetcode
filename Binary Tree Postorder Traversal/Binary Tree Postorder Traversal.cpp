#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
�������ĺ���ǵݹ鷽���������Ѷȸ��Ӻܶ� 
��Ҫ����һ��preָ�룬��ʾǰһ�������ʵĽڵ�

˼·��Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ�
��˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ��
�������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ� 
*/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) 
{
    vector<int> result; 
    //if (root == NULL)
    //   return NULL; 
    stack<TreeNode*> s;
    TreeNode *pre = NULL;
    if (root) 
        s.push(root);
    else
        return result;
    while (!s.empty())
    {
            TreeNode *p = s.top();
            if ( (p->left == NULL && p->right ==NULL) || (pre != NULL && (pre == p->left || pre == p->right)) )
            {
                 result.push_back(p->val);
                 s.pop();
                 pre = p;
            } 
            else//(p->left || p->right)
            {
                if (p->right)
                    s.push(p->right);
                if (p->left)
                    s.push(p->left);
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
    result = postorderTraversal(n1); 
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
