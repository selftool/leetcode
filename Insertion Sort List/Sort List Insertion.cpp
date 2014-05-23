#include <iostream>
//����Ĳ������� 
//���Ӷ�O(n*n)�������ʱ�ˡ��� 
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addNode(ListNode*& head, int val) //��Ϊ��ı�headָ���ֵ������headҪ�����ô��� 
{   
    if ( head == NULL )
    {
        //ListNode* newNode = new ListNode(val);
        head = new ListNode(val);
        return;
    }
    ListNode* pNode = head;
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
    }
    pNode->next = new ListNode(val);
}

void printList( ListNode* head )
{
    ListNode* pNode = head;
    if (head == NULL) return ;
    while (pNode != NULL)
    {
          cout << pNode->val << " ";
          pNode = pNode->next;
    }
    cout << endl;
}

ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *pNode = head->next;//������ֱ�Ӵӵ�2���ڵ㿪ʼ ����1���ڵ���Ϊ���������ĳ�ʼ״̬
    head->next = NULL;
    while (pNode != NULL)
    {
          ListNode *pCur = pNode;
          //cout << pCur->val << endl;
          pNode = pNode->next;
          ListNode *ptr = head;
          if ( ptr->val > pCur->val )
          {
               pCur->next = ptr;
               head = pCur;
          }
          else
          {
               while (ptr != NULL && ptr->next != NULL)
               {
                    if (ptr->next->val > pCur->val)
                    {
                        break;
                    }
                    else
                    {
                        ptr = ptr->next; 
                    }
               }
               pCur->next = ptr->next;
               ptr->next = pCur;
          }
    }
    
    return head;
}

int main()
{
    ListNode *head = NULL;//new ListNode(2);
    addNode(head, 2);
    addNode(head, 4);
    addNode(head, 6);
    addNode(head, 1);
    addNode(head, 3);
    addNode(head, 5);
    printList(head);
    printList(insertionSortList(head)); 
    
    system("pause");
    return 0;
} 
