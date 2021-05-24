#include<iostream>

//Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val) return head->next;

		ListNode *pre = head, *curr = head->next;
		while (curr != nullptr) {
			if (curr->val == val) {
				pre->next = curr->next;
			}
			pre = curr;
			curr = curr->next;
		}

		return head;
	}

	void insert(ListNode *head, int val)// ͷ�巨
	{
		ListNode *node = new ListNode(val);

		if (node != nullptr) {
			node->next = head->next;
			head->next = node;
		}
	}

	void createAList(ListNode *head, std::initializer_list<int> vec)
	{
		for (auto it = vec.begin(); it != vec.end(); it++) {
			this->insert( head, *it );
		}
	}

	void printList(ListNode *head)
	{
		ListNode *p = head;

		while (p != nullptr) {
			std::cout << p->val << std::endl;
			p = p->next;
		}
	}
};

int main()
{
	ListNode head(4);
	Solution s;
	s.createAList(&head, { 9, 1, 5 });
	s.printList(&head);

	s.deleteNode( &head, 5 );
	s.printList(&head);

	return 0;
}