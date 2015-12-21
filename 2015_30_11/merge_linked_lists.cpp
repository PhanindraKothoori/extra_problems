#include <stdio.h>
#include<conio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};

void print(struct node *head){
	struct node *temp=head; 
	while (temp != NULL)
	{
		printf("%d ->", temp->num);
		temp = temp->next;
	}
	printf("null \n");
}

void testCase(); //normal case

struct node * create(int x) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->num = x;
	temp->next = NULL;
	return temp;
}
struct node * merge_list(struct node *head1, struct node *head2) {
	struct node *head, *temp;
	if (head1 && head2){
		if (head1->num < head2->num){
			head = head1;
			head1 = head1->next;
		}
		else{
			head = head2;
			head2 = head2->next;
		}
		temp = head;
		while (head1 != NULL && head2 != NULL){
			if (head1->num < head2->num){
				temp->next = head1;
				temp = head1;
				head1 = head1->next;
			}
			else{
				temp->next = head2;
				temp = head2;
				head2 = head2->next;
			}
		}
		while (head1){
			temp->next = head1;
			temp = head1;
			head1 = head1->next;
		}
		while (head2){
			temp->next = head2;
			temp = head2;
			head2 = head2->next;
		}
		return head;
	}
	else return head1 ? head1 : head2;
}
int main()
{
	testCase();

	getch();
	return 0;
}


void testCase(){

	printf("-----------------TEST CASE 1:----------------\n");
	struct node *Node, *start, *head;
	int a[] = { 1, 2, 6, 9 };
	int b[] = { 3, 4, 5, 7 };

	//CREATING LINKED LIST 1
	int i = 0;
	start = create(a[i]);
	Node = start;
	for (i = 1; i<4; i++)
	{
		Node->next = create(a[i]);
		Node = Node->next;
	}
	struct node *head1 = start;


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

	//PRINTING THEM
	struct node *start1 = head1, *start2 = head2;
	print(start1);
	print(start2);

	//CALLING THE FUNCTION
	head = merge_list(head1, head2);
	while (head != NULL)
	{
		printf("%d ->", head->num);
		head = head->next;
	}
	printf("null \n\n\n");

}

