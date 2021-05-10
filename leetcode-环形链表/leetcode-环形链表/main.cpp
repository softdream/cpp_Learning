#include <iostream>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		std::unordered_set<ListNode*> set;
		while (head != nullptr) {
			if (set.count(head))
				return true;
			set.insert( head );
			head = head->next;
		}
		return false;
	}
};

int main()
{


	return 0;
}