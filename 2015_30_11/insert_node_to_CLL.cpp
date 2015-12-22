#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {
	struct node *next;
	int num;
};


void insert_node(struct node *head, int num, int pos){
	if (pos == 0){//insert at head
		struct node *temp = head;
		do{
			temp = temp->next;
		} while (temp->next != head->next);

		
		struct node *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->num = num;
		newNode->next = head->next;
		head->next = newNode;
		temp->next = newNode;

		return;
	}


	int i = 0;
	struct node *temp = head;
	while (i < pos){
		temp=temp->next;
		i++;
	}
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = temp->next;
	temp->next = newNode;
}

void insert_node(struct node* head, int num){//default insert at the end
	struct node *temp=head;
	do{
		temp = temp->next;
	} while (temp->next != head->next);
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = temp->next;
	temp->next = newNode;
}

void myprint(struct node* head){
	struct node * temp = head;
	temp = temp->next;
	do{
		printf("%d->", temp->num);
		temp = temp->next;
	} while (temp != head->next);
	printf("null\n");
}


struct node * create(int x) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->num = x;
	temp->next = NULL;
	return temp;
}

int main(){
	//create a circular linked list.
	struct node *head = (node*)malloc(sizeof(struct node)), *Node;
	head->num = NULL;
	head->next = head;
	struct node *start = (node*)malloc(sizeof(struct node));
	start->num = 1;
	start->next = start;
	head->next = start;
	Node = start;
	int a[] = { 1, 2, 3, 4, 5, 6 }, i=0;
	for (i = 1; i < 6; i++){
		Node->next = create(a[i]);
		Node = Node->next;
	}
	Node->next = start;
	
	//test cases
	insert_node(head, 10, 3);
	myprint(head);

	insert_node(head, 100, 0);
	myprint(head);

	insert_node(head, 1000);
	myprint(head);
	getch();
	return 0;
}