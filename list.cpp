/** \file list.cpp
*   \brief List functions code
*/

#include <stdio.h>
#include <conio.h>

/** \struct List
*   \brief Struct is implementation of singly-linked list
*/
struct List {
	int number;
	List *next;
};

/** \fn void Push(List **head, int data)
*   \brief Function pushes new element at the end of list
*
*	\param **head - list head pointer-pointer
*   \param value - value of element
*   <br>tmp - temporary list
*/
void Push(List **head, int value) {
	List *tmp=new List;
	tmp->number=value;
	tmp->next=*head;
	*head=tmp;
};

/** \fn List* Get(List* head, int i)
*	\brief Function returns pointer to i-th element
*
*	\param *head - list head pointer
*	\param i - place of element
*	<br>k - counter
*/
List* Get(List* head, int i) {
	int k=0;
	while ((k<i)&&head) {
		head=head->next;
		k++;
	}
	return head;
}


/** \fn void Insert(List *head, int i, int val)
*	\brief Function inserts i-th element
*
*	\param *head - list head pointer
*	\param i - place of new element
*	\param val - value of i-th element
*	<br>*tmp - temporary list pointer
*/
void Insert(List *head, int i, int val) {
	List *tmp=NULL;
	int k=0;
	while ((k<i)&&head->next) {
		head=head->next;
		k++;
	}
	tmp=new List;
	tmp->number=val;
	if (head->next) tmp->next=head->next;
	else tmp->next = NULL;
	head->next=tmp;
}

/** \fn void Pop(List **head, int n)
*	\brief Function deletes i-th element
*
*	\param **head - list head pointer-pointer
*	\param i - place of old element
*	<br>*prev - list pointer returning (i-1)-th place
*	<br>*then - list pointer returning place of the next element
*	<br>val - value of this element
*/
void Pop(List **head, int i) {
	if (*head==NULL) return;
	else {
		List *prev=Get(*head, i-1);
		List *then=prev->next;
		int val=then->number;
		prev->next=then->next;
		delete then;
	}
}

/** \fn void Show(List *head, int n)
*	\brief Function returns values of the whole list
*
*	\param *head - list head pointer
*	\param n - number of elements
*	<br>i - counter
*/
void Show(List *head, int n) {
	int i=n;
	while (head) {
		printf("%d: %d\n",i,head->number);
		head=head->next; i--;
	}
}

int main()
{
	int n=0,p=0,q=0;
	printf("Input number of elements: ");
	scanf("%d",&n);
	List *head=NULL;
	for (int i=0; i<n; i++){
		int j=0;
		printf("Element # %d: ",i+1);
		scanf("%d",&j);
		Push(&head, j);
	};
	printf("Add element # ");
	scanf("%d",&p);
	printf("Its value: "); scanf("%d",&q);
	Insert(head, p, q);
	printf("Delete element # ");
	scanf("%d",&p);
	Pop(&head, p);
	printf("\n");
	Show(head,n);
	
	getch();
}