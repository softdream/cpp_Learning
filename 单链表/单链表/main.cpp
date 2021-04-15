#include <iostream>
#include <stdlib.h>

#include <forward_list>

std::forward_list<int> list{10, 20, 30};

/* 链表的一个节点 */
typedef struct TNode {
	int data; // 数据域
	struct TNode *next;// 指针域
}TNode, *TNodePtr;

bool initLinkList(TNode **linkList)
{
	*linkList = (TNode*)malloc(sizeof(TNode));
	if (!linkList) {
		std::cout << "分配内存失败！" << std::endl;
		return false;
	}
	(*linkList)->next = NULL;
	std::cout << "link = " << *linkList << std::endl;
	return true;
}

/* 插入一个新的数据到单链表中, 使用头插法 */
//参数：node：单个节点的指针
//参数：data：插入的数据
bool insert( TNode **linkList, int data)
{
	//std::cout << "link = " << *linkList << std::endl;
	TNodePtr node = NULL;
	node = ( TNode* )malloc( sizeof( TNode ) );
	if (!node) {
		//std::cout << "分配内存失败！" << std::endl;
		printf( "分配内存失败！\n" );
		return false;
	}
	node->data = data;
	node->next = (*linkList)->next;
	(*linkList)->next = node;
	return true;
}

/* 删除节点 */
//形参：data：要删除的元素
//形参：linkList：单链表头指针
bool deleNode(TNode **linkList, int data)
{
	//std::cout << "link4 = " << *linkList << std::endl;
	if (!(*linkList)) {
		return false;
	}
	TNode *ptr = *linkList;
	while (ptr->next != NULL) {
		if (ptr->next->data == data) {
			TNode *node = NULL;
			node = ptr->next;
			ptr->next = ptr->next->next;
			free( node );
		}
		else {
			ptr = ptr->next;
		}
	}
	return true;
}

/* 打印链表 */
void printLinkList(TNode **linkList)
{
	int nodeCount = 0;
	if (*linkList == NULL) {
		exit( -1 );
	}
	TNode *ptr = *linkList;
	while (ptr->next != NULL) {
		ptr = ptr->next;
		nodeCount++;
		printf("第 %d 个数据是：%d\n", nodeCount, ptr->data);
		//std::cout << "第 " << nodeCount << "个数据是：" << linkList->next << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}

int main()
{
	/*TNode *link = NULL ;// 定义一个单链表
	if (initLinkList(&link)) printf( "初始化成功！" );
	else printf( "初始化失败！" );

	//std::cout << "link = " << link << std::endl;

	if (insert(&link, 10)) 
		std::cout << "插入了一个节点 ..." << std::endl;
	else 
		std::cout << "插入节点失败 ..." << std::endl;
	if (insert(&link, 20))
		std::cout << "插入了一个节点 ..." << std::endl;
	else
		std::cout << "插入节点失败 ..." << std::endl;
	if (insert(&link, 30)) 
		std::cout << "插入了一个节点 ..." << std::endl;
	else
		std::cout << "插入节点失败 ..." << std::endl;
	if (insert(&link, 40))
		std::cout << "插入了一个节点 ..." << std::endl;
	else
		std::cout << "插入节点失败 ..." << std::endl;

	printLinkList( &link );

	if (deleNode(&link, 20))
		std::cout << "删除一个节点 ..." << std::endl;
	else
		std::cout << "删除节点失败 ..." << std::endl;
	if (deleNode(&link, 10))
		std::cout << "删除一个节点 ..." << std::endl;
	else
		std::cout << "删除节点失败 ..." << std::endl;
	printLinkList(&link);*/

	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++) {
		i++;
		std::cout << "第 " << i << " 个元素是：" << *it << std::endl;
	}
	return 0;
}