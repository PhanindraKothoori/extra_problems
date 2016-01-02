
//Given a linked list which is in pattern like combination of ascending and descending.Sort it.
//(First all ascending numbers occur, next all descending nums)
//Note : min of descending part is greater than max of ascending
//Ex : Input 1->2->7->20->15->10
//Output 1->2->7->10->15->20


/*
we can use reverse for this solution. since the reverse of descending would result in ascending, we can use that.
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

struct node * sort(struct node *head){
	struct node *temp;
	temp = head;
	while (temp && temp->next){
		if (temp->next->num > (temp->next->next)->num){
			temp->next = reverse(temp->next);
			break;
		}
		else temp = temp->next;
	}
	return head;
}

int main(){
	struct node *start, *Node;
	int a[] = { 1, 2, 3, 4, 10, 9, 8, 7, 6, 5 };
	start = create(a[0]);
	Node = start;
	for (int i = 1; i < 10; i++){
		Node->next = create(a[i]);
		Node = Node->next;
	}
	print(start);
	start = sort(start);
	print(start);
	getch();
	return 0;
}