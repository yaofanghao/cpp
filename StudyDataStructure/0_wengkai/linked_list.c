// 翁恺C语言p124-p128
// 链表的应用
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value; 
    struct _node* next; 
}Node;

int main(int argc, char const *argv[]){
    
    Node *head = NULL;  //creat head node
    int number;
    do{
        scanf("%d", &number);
        if(number != -1){
            // add to linked-list
            Node *p = (Node*)malloc(sizeof(Node));
            p->value = number;
            p->next = NULL;

            // find the last
            Node *last = head;
            if(last){
                while(last->next){
                    last = last->next;
                } 
                last->next = p;               
            }
            else{
                head = p;
            }
            
        }
    }while(number != -1);
    
}

// void Insert(int x){
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     // (*temp).data = x;
//     temp->data = x;
//     temp->next = NULL;
//     if(head != NULL){
//         temp->next = head;
//     }
//     head = temp;
// }

// void Print(){
//     struct Node* temp = head;
//     printf("list is");
//     while(temp != NULL){
//         printf("%d",temp->data);
//         temp = temp->next;
//     }
//     printf("\n");

// }