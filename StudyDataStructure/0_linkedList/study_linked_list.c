// https://www.bilibili.com/video/BV1Rb411F738
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// 结构体函数
// 创建表头
struct Node* createList(){
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

// 创建结点
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入结点
void insertNodeByHead(struct Node* headNode, int data){
    struct Node* newNode = createNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

// 删除结点
void deleteNodeByAppoin(struct Node* headNode, int posData){
    struct Node* posNode = headNode->next;
    struct Node* posNodeFront = headNode;
    while(posNode){
        while(posNode->data != posData){
            posNodeFront = posNode;
            posNode = posNodeFront->next;
            while(posNode==NULL){
                printf("do not find");
                return;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return;
    }
}

void printList(struct Node* headNode){
    struct Node* pMove = headNode->next;
    while(pMove){
        printf("%d\t", pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}

int main(){
    // struct Node Node1 = {1,NULL};
    // struct Node Node2 = {2,NULL};
    // struct Node Node3 = {3,NULL};
    // Node1.next = &Node2;
    // Node2.next = &Node3;

    struct Node* list =createList();
    printList(list);
    insertNodeByHead(list,1);
    insertNodeByHead(list,3);
    insertNodeByHead(list,2);
    printList(list);  // 2 3 1
    deleteNodeByAppoin(list, 2);  
    printList(list);  // 3 1
    return 0;
}
