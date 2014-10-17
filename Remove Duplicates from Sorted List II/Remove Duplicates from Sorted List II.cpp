// Remove Duplicates from Sorted List II
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList (ListNode *head) {
	if (NULL == head) return ;
	bool first = true;
	while (head != NULL) {
		if (first) {
			cout << head->val;
			first = false;
		}
		else {
			cout << "->" << head->val;
		}
		head = head->next;
	}
	cout << endl;
	
}

ListNode *deleteDuplicates(ListNode *head) {
	if (NULL == head) return NULL;
	if (NULL == head->next) return head;
	int temp = head->val;
	int repeat = 0;
	ListNode *new_head = new ListNode(-1); // �������dummy head; 
	ListNode *tail = new_head; // �������β�� 
	ListNode *cur = head->next;
	ListNode *pre = head;
	while (cur) {
		if (cur->val == temp) {
			repeat = 1; // �����ظ���temp 
			pre = cur;
			cur = cur->next;
		}
		else {
			temp = cur->val; // ����temp 
			if (0 == repeat) { // ǰһ��tempû�г����ظ���˵��ǰһ��tempֵ��Ԫ���ǲ��ظ��� 
				tail->next = pre;
				tail = pre;
				tail->next = NULL;
			} 
			repeat = 0;
			pre = cur; 
			cur = cur->next;
		}
	} 
	if (0 == repeat) tail->next = pre; // ��β�ͽ��� 
	
	return new_head->next;
}

int main() {
	ListNode *n0 = new ListNode(1);
	ListNode *n1 = new ListNode(1);  // 1->1->2->3->4->4->4->5
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(4);
	ListNode *n7 = new ListNode(5);
	
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	
	printList(n0);
	printList(deleteDuplicates(n0));
	
	return 0;
} 


