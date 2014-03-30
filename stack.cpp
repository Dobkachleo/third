/** \file stack.cpp
*	\brief Stack implementation code
*/

#include <stdio.h>
#include <conio.h>

/** \class stack
*	\brief Stack functions
*/
class stack {
private:
	int top;
	int s[1000];
public:
	/** \fn stack()
	*	\brief Stack initialization
	*/
	stack() {
		top=0;
	}
	/** \fn int push(int val)
	*	\brief Function adds new element
	*
	*	\param val - value of new element
	*/
	int push(int val) {
		top++;
		s[top]=val;
		return val;
	}
	/** \fn int pop()
	*	\brief Function deletes head of stack
	*	<br>Details<br>val - value of old head
	*/
	int pop() {
		int val=s[top];
		top--;
		return val;
	}
	/** \fn friend void show(stack st)
	*	\brief Function is friend of class
	*	\param st - stack
	*	<br>Details<br>Function shows all elements of stack
	*/
	friend void show(stack st);
	/** \fn void first()
	*	\brief Function shows value of stack head
	*/
	void first() {
		printf("Head of stack: %d\n",s[top]);
	}
};

void show(stack st){
	for(int i=st.top; i>0; i--) printf("%d ",st.s[i]);
	printf("\n\n");
}

int main () {
	int n=0;
	printf("Input number of elements: ");
	scanf("%d",&n);
	stack S;
	for (int i=0; i<n; i++){
		int j=0;
		printf("Element # %d: ",i+1);
		scanf("%d",&j);
		S.push(j);
	}
	printf("\n"); show(S); S.first();
	printf("We deleted head of stack\n"); S.pop();
	show(S);
	getch();
}