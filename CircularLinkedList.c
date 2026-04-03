#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"

// 공백 원형 연결 리스트 생성
linkedList_h* createLinkedList_h(void) {
    linkedList_h* CL;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL->head = NULL;
    return CL;
}

// 원형 연결 리스트 출력
void printList(linkedList_h* CL) {
    listNode* p;
    printf("CL = (");
    p = CL->head;
    if (p == NULL) {
        printf(") \n");
        return;
    }
    do {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->head) printf(", ");
    } while (p != CL->head);
    printf(") \n");
}

// 첫 번째 노드로 삽입
void insertFirstNode(linkedList_h* CL, char* x) {
    listNode* newNode, * temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (CL->head == NULL) { // 리스트가 비어있는 경우
        CL->head = newNode;
        newNode->link = newNode;
    }
    else { // 리스트가 비어있지 않은 경우
        temp = CL->head;
        while (temp->link != CL->head) {
            temp = temp->link;
        }
        newNode->link = CL->head;
        temp->link = newNode;
        CL->head = newNode;
    }
}

// 중간 노드로 삽입
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (CL->head == NULL) { // 리스트가 비어있는 경우
        CL->head = newNode;
        newNode->link = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

// 마지막 노드로 삽입
void insertLastNode(linkedList_h* CL, char* x) {
    listNode* newNode, * temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (CL->head == NULL) { // 리스트가 비어있는 경우
        CL->head = newNode;
        newNode->link = newNode;
    }
    else {
        temp = CL->head;
        while (temp->link != CL->head) {
            temp = temp->link;
        }
        newNode->link = CL->head;
        temp->link = newNode;
    }
}

// 노드 삭제
void deleteNode(linkedList_h* CL, listNode* old) {
    listNode* pre;
    if (CL->head == NULL) return;
    if (CL->head->link == CL->head) { // 리스트에 노드가 하나만 있는 경우
        free(CL->head);
        CL->head = NULL;
        return;
    }
    else if (old == NULL) return;
    else {
        pre = CL->head;
        while (pre->link != old) {
            pre = pre->link;
        }
        pre->link = old->link;
        if (old == CL->head) CL->head = old->link;
        free(old);
    }
}

// 노드 탐색
listNode* searchNode(linkedList_h* CL, char* x) {
    listNode* temp;
    temp = CL->head;
    if (temp == NULL) return NULL;

    do {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    } while (temp != CL->head);

    return NULL;
}