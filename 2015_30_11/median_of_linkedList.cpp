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