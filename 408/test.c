#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node, *PNode;

Node head1;
head1.data = 1;
Node head2;
head2.data = 2;
head1.next = &head2;

Node head3;
head1.data = 3;
Node head4;
head2.data = 4;
head3.next = &head4;

void changeNode(PNode pl)
{
	pl = &head3;
}



int main()
{
	printf("%d", head1.data);
	changeNode(&head1);
	printf("%d", head1.data);
	system("chcp 65001");
	return 0;
}
