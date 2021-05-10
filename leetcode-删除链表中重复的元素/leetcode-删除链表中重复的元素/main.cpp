#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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

	bool insert(ListNode *head, int value)
	{
		ListNode *node = new ListNode(value);
		if (node == nullptr) {
			return false;
		}

		node->next = head->next;
		head->next = node;
		return true;
	}


	void printList(ListNode *head) {
		ListNode *p = head->next;
		int count = 0;
		while (p != nullptr) {
			std::cout << "node " << count << ": " << p->val << std::endl;
			count++;
			p = p->next;
		}
	}

	void createAList(ListNode *head, std::initializer_list<int> init)
	{
		for (auto it : init) {
			insert(head, it);
		}
	}

	// 反向打印链表
	vector<int> reversePrint(ListNode* head)
	{
		std::stack<ListNode*> stack;
		std::vector<int> vec;

		ListNode *p = head;
		while (p != nullptr) {
			stack.push(p);
			p = p->next;
		}

		while (!stack.empty()) {
			ListNode *n = stack.top();
			vec.push_back(n->val);
			stack.pop();
		}
		return vec;
	}

	// 删除链表中重复的元素
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode *p = head->next;
		ListNode *ret = p;

		while (p != nullptr && p->next != nullptr ) {
			if (p->val == p->next->val) {
				p->next = p->next->next; // 删除
			}
			p = p->next;
		}
		return ret;
	}
};

int main()
{
	Solution s;

	ListNode list(0);

	s.createAList(&list, { 3, 3, 2, 1, 1 });

	s.printList(&list);
	std::cout << "-----------------------" << std::endl;

	ListNode *ret = s.deleteDuplicates( &list );
	s.printList(ret);

	return 0;
}