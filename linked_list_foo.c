#include <stdio.h>
#include "node.c"
//1. createNode
Node* createNode(int value){
    Node *head = (Node*) malloc(sizeof(Node));
    head->val = value;
    head->next = NULL;
    return head;
}

//2. insertAtEnd
void insertAtEnd(Node **head, int value){
    if(!(*head)){ 
        *head = createNode(value);
        return;
    }
    Node *ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    (*ptr)->next = creatNode(value);
}

//3. insertAtFront
void insertAtFront(Node **head, int value){
    Node *new = createNode(value);
    new->next = *head;
    *head = new;
}

//4. insertAt
void insertAt(Node **head, int index, int value){
    if(index == 0) insertAtFront(head, value);
    Node *ptr = *head;
    while((index - 1) && ptr->next){
        ptr = ptr->next;
        --index;
    }
    if(!(ptr->next)) return;
    Node *new = createNode(value);
    new->next = ptr->next;
    ptr = new;
}

//5. deleteNode
void deleteNode(Node **head, int value){
    if(!(*head)) return;
    if((*head)->val == value){
        Node *tmp = (*head)->next;
        free(*head);
        *head = tmp;
        return;
    }
    Node *ptr = *head;
    while(((ptr->next)->val != value) && (ptr->next != NULL)) ptr = ptr->next;
    if(!(ptr->next)) return;
    Node *remove = ptr;
    ptr = (ptr->next)->next;
    free(remove);
}

//6. removeFront
void removeFront(Node **head){
    if(!(*head)) return;
    Node *tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

//7. removeBack
void removeBack(Node **head){
    if(!(*head)) return;
    Node *ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

//8. removeAt
void removeAt(Node **head, int index){
    if(!index) removeFront(head);
    Node *ptr = *head;
    while((index - 1) && ptr->next){
        ptr = ptr->next;
        --index;
    }
    if(!(ptr->next)) return;
    Node *remove = ptr->next;
    ptr = (ptr->next)->next;
    free(remove);
}

//9. search
Node *search(Node *head, int val){
    if(!(head)){
        printf("List is empty");
        return NULL;
    }
    while(head && head->val != val){
        head = head->next;
    }
    return head;
}

//10. printList
void printList(Node *head){
	if(!(head)){
		printf("List is empty\n");
		return;
	}
	while(head){
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}
//11. freeList
void freeList(Node **head){
	if(!(*head)) return;
	Node *tmp;
	while(tmp){
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}


