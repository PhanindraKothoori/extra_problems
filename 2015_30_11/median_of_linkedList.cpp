/*
Assuming median as the floor(n/2)th node.
*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node* next;
};

struct node* findMedian(struct node* head){
	struct node *p1, *p2;
	p1 = p2 = head;
	while (head && p1->next && (p1->next)->next){
		p1 = (p1->next)->next;
		p2 = p2->next;
	}
	return p2;
}
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
int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 1, 2, 3, 4 };

	//CREATING LINKED LIST 1
	int i = 0;
	start = create(a[i]);
	Node = start;
	for (i = 1; i<5; i++)
	{
		Node->next = create(a[i]);
		Node = Node->next;
	}
	struct node *head1 = start;
	print(head1);
	printf("%d\n", findMedian(head1)->num);

	//CREATING LINKED LIST 2
	i = 0;
	start = create(b[i]);
	Node = start;
	for (i = 1; i<4; i++)
	{
		Node->next = create(b[i]);
		Node = Node->next;
	}
	struct node *head2 = start;
	print(head2);
	printf("%d\n", findMedian(head2)->num);


	getch();
	return 0;
}