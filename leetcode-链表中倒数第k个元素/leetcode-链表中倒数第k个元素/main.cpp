#include <iostream>

// Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

class Solution {
public:
	//双指针法，快慢指针，快指针比慢指针多走k步，快指针到头的时候，慢指针指的元素就是倒数第k个
	ListNode* getKthFromEnd(ListNode* head, int k)
	{
		ListNode *fast = head->next, *slow = head->next;
		int count = 0;
		while (fast != nullptr) {
			count++;
			if (count > k) {
				slow = slow->next;
			}
			fast = fast->next;
		}
		return slow;
	}

	bool insert( ListNode *head, int value )
	{
		ListNode *node = new ListNode( value );
		if (node == nullptr) {
			return false;
		}

		node->next = head->next;
		head->next = node;
		return true;
	}


	void printList( ListNode *head) {
		ListNode *p = head->next;
		int count = 0;
		while (p != nullptr) {
			std::cout << "node " << count << ": " << p->val << std::endl;
			count++;
			p = p->next;
		}
	}

	void createAList( ListNode *head, std::initializer_list<int> init )
	{
		for (auto it : init) {
			insert(head, it);
		}
	}
};

int main()
{
	Solution s;

	ListNode list(0);
	
	s.createAList(&list, {1});

	s.printList(&list);

	ListNode *ret = s.getKthFromEnd( &list, 1 );

	std::cout << "ret = " << ret->val << std::endl;

	return 0;
}