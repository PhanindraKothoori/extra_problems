
//Sorted a linked list which is in ascending order but two numbers are changed, i mean not in the usual order they need to be
//Ex : 1->2->3->15->10->4->20; O / p:1 - 2 - 3 - 4 - 10 - 15 - 20

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

struct node * sort_unusual(struct node *head){
	struct node *temp,*a,*b;
	temp = head;
	while (temp && temp->next){
		if (temp->num > temp->next->num){
			a = temp;
			temp = temp->next;
			while (temp->next){
				if (temp->num > temp->next->num){
					b = temp->next;
					a->num = a->num + b->num;
					b->num = a->num - b->num;
					a->num = a->num - b->num;
					break;
				}
				else temp = temp->next;
			}
			break;
		}
		else temp = temp->next;
	}
	return head;
}

int main(){
	struct node *start, *Node;
	int a[] = { 1, 2, 3, 4, 10, 6, 7, 8, 9, 5 };
	start = create(a[0]);
	Node = start;
	for (int i = 1; i < 10; i++){
		Node->next = create(a[i]);
		Node = Node->next;
	}
	print(start);
	start = sort_unusual(start);
	print(start);
	getch();
	return 0;
}