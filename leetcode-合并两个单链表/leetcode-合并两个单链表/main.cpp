#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;

		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

void insert(ListNode *lst, int value) // ͷ�巨
{
	ListNode *node = new ListNode( value );
	//std::cout << "node.val = " << node->val << std::endl;
	node->next = lst->next;
	lst->next = node;
	
}

void createListByArray(ListNode *lst, int *ary, int length)
{
	for (int i = 0; i < length;  i++) {
		insert( lst, ary[i] );
	}
}

void printList(ListNode *lst)
{
	int i = 0;
	ListNode *ptr = lst->next;
	while (ptr != nullptr) {
		std::cout << "value[" << i << "] = " << ptr->val << std::endl;
		ptr = ptr->next;
		i++;
	}
}

int main()
{
	int ary1[3] = { 4, 2, 1 };
	int ary2[3] = { 5, 3, 1 };

	ListNode lst1, lst2;

	createListByArray( &lst1, ary1, 3 );
	printList( &lst1);

	std::cout << "----------------------" << std::endl;
	createListByArray(&lst2, ary2, 3);
	printList(&lst2);

	std::cout << "----------------------" << std::endl;
	Solution s;
	ListNode * ret = s.mergeTwoLists(&lst1, &lst2);
	printList( ret );
	return 0;
}