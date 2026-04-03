#pragma once

// 이중 연결 리스트의 노드 구조 설계
typedef struct ListNode {
	struct ListNode* llink; // 왼쪽(이전) 노드 포인터
	char data[4];
	struct ListNode* rlink; // 오른쪽(다음) 노드 포인터
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);
