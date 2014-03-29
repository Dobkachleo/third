/** \file list.cpp
*   \brief List functions code
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>

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
*   \var tmp - temporary list
*/
void Push(List **head, int value) {
	List *tmp=new List;
	tmp->number=value;
	tmp->next=*head;
	*head=tmp;
};

/**
@function Take
Function that take the element of the list. Shifts the pointers of the elements, returning the value of the specific number.
@param last – list for temporary copy
@return element from the list
*/
/*int Take(List **head) {
	List* last = NULL;
	if (head == NULL) {
		return 0;
	}
	last = (*head);
	int val = last->number;
	(*head) = (*head)->next;
	delete last;
	return val;
};

/** \fn List* Get(List* head, int i)
*	\brief Function returns pointer to i-th element
*
*	\param *head - list head pointer
*	\param i - place of element
*	\param k - counter
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
*	\var *tmp - temporary list pointer
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
*	\var *prev - list pointer returning (i-1)-th place
*	\var *then - list pointer returning place of the next element
*	\var val - value of this element
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

/** \fn void Show(List *head)
*	\brief Function returns values of the whole list
*
*	\param *head - list head pointer
*	\param n - number of elements
*	\var i - counter
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
	setlocale(LC_ALL,"rus");

	int n=0,p=0,q=0;
	printf("Введите количество элементов списка: ");
	scanf("%d",&n);
	List *head=NULL;
	for (int i=0; i<n; i++){
		int j=0;
		printf("Элемент № %d: ",i+1);
		scanf("%d",&j);
		Push(&head, j);
	};
	printf("Добавить элемент под номером ");
	scanf("%d",&p);
	printf("Его значение: "); scanf("%d",&q);
	Insert(head, p, q);
	printf("Удалить элемент под номером ");
	scanf("%d",&p);
	Pop(&head, p);
	printf("\n");
	Show(head,n);
	
	getch();
}