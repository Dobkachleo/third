/** \file queue.cpp
*	\brief Queue implementation code
*/

#include <stdio.h>
#include <conio.h>

/** \class Queue
*	\brief Queue functions
*/
class Queue {
private:
	/** \param SIZE - maximum of queue length
	*	\param *queue - queue pointer
	*	\param head - head of queue
	*	\param tail - end of queue
	*/
	static const int SIZE=100; 
	int *queue; 
	int head, tail; 
public:
	/** \fn Queue()
	*	\brief Class constructor.
	*/
	Queue() {
		queue=new int[SIZE];
		head=tail=0; 
	}
	/** \fn void push (int num)
	*	\brief Function adds element in queue head
	*
	*	\param num - value of new element
	*/
	void push (int num) {
		if ((tail+1==head)||((tail+1==SIZE)&&!head)) { 
			printf("Queue is full\n"); 
			return ; 
		} 
		tail++; 
		if (tail==SIZE) tail=0 ;
		queue[tail]=num; 
	}
	/** \fn friend void show(Queue q)
	*	\brief Function is friend to class
	*
	*	\param q - queue
	*	<br>Details<br>Fuction shows all elements of queue
	*/
	friend void show(Queue q);
	/** \fn void pop()
	*	\brief Function deletes head of queue
	*/
	void pop() {
		if (head==tail ) { 
			printf("Queue is empty\n"); 
			return;
		} 
		head++; 
		if (head==SIZE) head=0;
	}
	/** \fn void first()
	*	\brief Function shows value of queue head
	*/
	void first() {
		printf("First element: %d\n\n",head+1);
	}
};
void show(Queue q){
	for(int i=q.head+1; i<q.tail+1; i++) printf("%d ",q.queue[i]);
	printf("\n");
}
int main () 
{
	Queue data; 
	int i,n; 
	for (i= 1 ; i <= 5 ; i++ ) { 
		data.push ( i ) ;} 
	printf("Original queue: ");
	show(data); data.first();
	printf("Input one more element: ");
	scanf("%d",&n); data.push(n);
	printf("Now queue has this view: ");
	show(data); data.first();
	printf("Element deleting\n");
	data.pop();
	printf("Current data: ");
	show(data); data.first();
	printf("Element adding: ");
	data.push(7); show(data);
	
	getch();
}