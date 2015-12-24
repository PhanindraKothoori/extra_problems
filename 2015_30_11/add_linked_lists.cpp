/*
reversing a linked list using recursion

this can be done using stacks. 
because addition is done from right to left, and stack uses top-down approach, both are analogous
i have used stacks. each linked list elements are extracted to a stack and addition is done by popping out an element from each stack
the remaining elements(if any) are appended to the new linked list.
here the addition of nodes to the linked list is done as head-addition.
this will work for variable sized linked lists too :)
*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

void print(struct node *head){
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("%d ->", temp->num);
		temp = temp->next;
	}
	printf("null \n");
}

struct node * create(int x) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->num = x;
	temp->next = NULL;
	return temp;
}

struct stack{
	short num[20];
	int top;
};

void push(struct stack *s, int n){
	if (s->top<19){
		(s->top)++;
		s->num[s->top] = n;
	}
}
int pop(struct stack *s){
	if (s->top>=0){
		return (int)s->num[(s->top--)];
	}
	else return -1;
}

struct node* makeList(struct stack *s1, struct stack *s2){
	struct node *head = NULL;
	int sum = 0, carry = 0;
	while (s1->top >= 0 && s2->top >= 0){
 		struct node *temp = (node*)malloc(sizeof(struct node));
		int a = pop(s1), b = pop(s2);
		sum = (a + b + carry);
		
		temp->num = (sum) % 10;
		temp->next = head;
		head = temp;
		carry = (sum) / 10;
	}
	while (s1->top>=0){
		struct node *temp = (node*)malloc(sizeof(struct node));
		int a = pop(s1);
		sum = (a + carry);
		
		temp->num = sum % 10;
		temp->next = head;
		head = temp;
		carry = sum / 10;
	}
	while (s2->top >= 0){
		struct node *temp = (node*)malloc(sizeof(struct node));
		int a = pop(s2);
		sum = (a + carry);
		
		temp->num = sum % 10;
		temp->next = head;
		head = temp;
		carry = sum / 10;
	}
	if (carry){
		struct node *temp = (node*)malloc(sizeof(struct node));
		temp->num = 1;
		temp->next = head;
		head = temp;
	}
	return head;
}


struct node * add_linked_lists(struct node *head1, struct node * head2){
	struct stack s1, s2;

	s1.top = -1;
	s2.top = -1;

	while (head1){
		push(&s1, head1->num);
		head1 = head1->next;
	}
	while (head2){
		push(&s2, head2->num);
		head2 = head2->next;
	}
	
	struct node *start = makeList(&s1, &s2);
	return start;
}


int main(){
	struct node *start, *Node, *head1, *head2;
	int a[] = { 1,2,9,9,9};
	start = create(a[0]);
	Node = start;
	
	for (int i = 1; i < 5; i++){
		Node->next = create(a[i]);
		Node = Node->next;
	}

	head1 = start;
	print(head1);
	int b[] = { 9,9,9,9 };
	start = create(b[0]);
	Node = start;
	
	for (int i = 1; i < 4; i++){
		Node->next = create(b[i]);
		Node = Node->next;
	}
	head2 = start;
	print(head2);

	struct node *sum = add_linked_lists(head1, head2);
	print(sum);
	getch();
	return 0;
}