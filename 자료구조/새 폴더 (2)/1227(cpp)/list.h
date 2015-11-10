#ifndef _LIST_H_
#define _LIST_H_

class Node
{
public:
	Member* data;		// Employee ���� ��ü ������ 
	Node * next;		// ���� ��带 ����Ű�� ������
	Node * prev;
public:
	Node(Member* _data, Node* _next, Node* _prev): data(_data), next(_next), prev(_prev) {}
};

class List
{
public:
	Node* head;
	Node* tail;
	int ncount;
public:
	List();

	void list_insert(Member* data);
	void list_print(Member* data);
	Member* list_search(char* ch);
};



#endif /*_LIST_H_*/