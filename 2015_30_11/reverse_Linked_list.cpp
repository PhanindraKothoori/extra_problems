/*
reversing a linked list using recursion
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

struct node * reverse(struct node * head)
{
	struct node * temp;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	temp = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

int main(){
	struct node *start, *Node;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	start = create(a[0]);
	Node = start;
	for (int i = 1; i < 10; i++){
		Node->next = create(a[i]);
		Node = Node->next;
	}
	print(start); 
	print(reverse(start));
	getch();
	return 0;
}