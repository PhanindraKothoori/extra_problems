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
/*
p1 moves two nodes in an iteration and p2 moves just 1.
so there is an interval between the head of the linked list, p1, and p2.
to be precise, p2 lies in between p1 and head
*/
float findMedian(struct node* head){
	struct node *p1, *p2;
	p1 = p2 = head;
	while (head && p1->next && (p1->next)->next){
		p1 = (p1->next)->next;
		p2 = p2->next;
	}
	if (p1->next == NULL)
		return p2->num;
	else
		return (float)(p2->num + p2->next->num) / 2;
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
	struct node *start, *Node;
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
	printf("%f\n", findMedian(head1));

	//CREATING LINKED LIST 2
	i = 0;
	start = create(b[i]);
	Node = start;
	for (i = 1; i<4; i++)
	{
		Node->next = create(b[i]);
		Node = Node->next;
	}
	//end case 1: length of the linked list = 1
	struct node *head2 = start;
	print(head2);
	printf("%f\n", findMedian(head2));

	//end case 2: length of the linked list = 2
	i = 0;
	start = create(b[i]);
	Node = start;
	print(start);
	printf("%f\n", findMedian(start));
	Node->next = create(2);
	print(start);
	printf("%f\n", findMedian(start));

	getch();
	return 0;
}