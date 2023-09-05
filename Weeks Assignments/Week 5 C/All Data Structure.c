#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

// Data Structure In C language

// Resizing array

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Resizing array
	int* list = malloc(3 * sizeof(int));
	if (list == NULL)
	{
		return 1;
	}
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	// int* temp = malloc(4 * sizeof(int));
	// if (temp == NULL)
	// {
	//   free(list);
	//	 return 1;
	// }
	// for (int i = 0 ; i < 3 ; i++)
	// {
	//	 temp[i] = list[i];
	// }
	// free(list);
	
int* temp = realloc(list, 4 * sizeof(int));
if (temp == NULL)
{
	free(list);
	return 1;
}
temp[3] = 4;
list = temp;
for (int i = 0; i < 4; i++)
{
	printf("%i\n", list[i]);
}
free(list); // = free(temp);
return 0;
}
*/


/*
// Linked List

#include <stdio.h>
#include <stdlib.h>

// 0 1 2 3 Stores in heab

typedef struct node
{
	int number;
	struct node* next;
}node;

int main()
{
	node* list = NULL; // Head
	node* n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	n->number = 1;
	n->next = NULL;
	list = n;

	n = malloc(sizeof(node));
	if (n == NULL)
	{
		free(list);
		return 1;
	}
	n->number = 2;
	n->next = NULL;
	list->next = n;

	n = malloc(sizeof(node));
	if (n == NULL)
	{
		free(list->next); // free the last node first
		free(list); // then free the first node not vice versa
		return 1;
	}
	n->number = 3;
	n->next = NULL;
	list->next->next = n;

	// linked list resizing (Insert)
	n = malloc(sizeof(node));
	if (n != NULL)
	{
		n->number = 0;
		n->next = NULL;
		n->next = list;
		list = n;
	}

	for (node* temp = list ; temp != NULL ; temp = temp->next)
	{
		printf("%i\n", temp->number);
	}

	while (list != NULL)
	{
		node* temp = list->next;
		free(list);
		list = temp;
	}
	return 0;
}
*/

/*

// Binary Search
// Trees = ( linked list + Binary Search )

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node* left;
	struct node* right;
}node;

void print_tree(node* root);
int search(node* tree, int number);

int main()
{
	node* tree = NULL; // Root
	node* n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	n->number = 2;
	n->left = NULL;
	n->right = NULL;
	tree = n; // Root

	n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	n->number = 1;
	n->left = NULL;
	n->right = NULL;
	tree->left = n;

	n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	n->number = 3;
	n->left = NULL;
	n->right = NULL;
	tree->right = n;

	search(tree, 1);

	print_tree(tree);

	return 0;
}

void print_tree(node* root)
{
	if (root == NULL)
	{
		return;
	}
	print_tree(root->left);
	printf("%i\n", root->number);
	print_tree(root->right);
	free(root);
}

int search(node* tree, int number)
{
	if (tree == NULL)
	{
		printf("Not found\n");
		return 1;
	}
	else if (number < tree->number)
	{
		printf("go left\n");
		return search(tree->left, number);
	}
	else if (number > tree->number)
	{
		printf("go right\n");
		return search(tree->right, number);
	}
	else
	{
		printf("found\n");
		return 0;
	}
}
// Can make By Hash Tables

*/

/*
// STACK Using Array

// Implementing Static Stack using an Array in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// N will be the capacity of the Static Stack
#define N 1000

// Initializing the top of the stack to be -1
int top = -1;

// Initializing the stack using an array
int stack[N];

// Function prototypes
void push();       // Push element to the top of the stack
int pop();         // Remove and return the top most element of the stack
int peek();        // Return the top most element of the stack
bool isEmpty();    // Check if the stack is in Underflow state or not
bool isFull();     // Check if the stack is in Overflow state or not

int main(){
	printf("STATIC ARRAY (Total Capacity: %d)\n", N);
	int choice;

	while(1){
		printf("\nChoose any of the following options:\n");
		printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
		printf(" 4: Check if the stack is empty     5: Check if the stack is full\n\n");
		scanf("%d", &choice);

		switch(choice){
			case 0: exit(0);
			case 1: push(); break;
			case 2: pop(); break;
			case 3: peek(); break;
			case 4: isEmpty(); break;
			case 5: isFull(); break;
			default: printf("Please choose a correct option!");
		}
	}
	return 0;
}

void push(){
	// Checking overflow state
	if(top == N-1)
		printf("Overflow State: can't add more elements into the stack\n");
	else{
		int x;
		printf("Enter element to be pushed into the stack: ");
		scanf("%d", &x);
		top+=1;
		stack[top] = x;
	}
}

int pop(){
	// Checking underflow state
	if(top == -1)
		printf("Underflow State: Stack already empty, can't remove any element\n");
	else{
		int x = stack[top];
		printf("Popping %d out of the stack\n", x);
		top-=1;
		return x;
	}
	return -1;
}

int peek(){
	int x = stack[top];
	printf("%d is the top most element of the stack\n", x);
	return x;
}

bool isEmpty(){
	if(top == -1){
		printf("Stack is empty: Underflow State\n");
;        return true;
	}
	printf("Stack is not empty\n");
	return false;
}

bool isFull(){
	if(top == N-1){
		printf("Stack is full: Overflow State\n");
		return true;
	}
	printf("Stack is not full\n");
	return false;
}
*/


/*
// STACK Using Linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void push();       // Push element to the top of the stack
int pop();         // Remove and return the top most element of the stack
int peek();        // Return the top most element of the stack
bool isEmpty();    // Check if the stack is in Underflow state or not

struct node{
	int val;
	struct node *next;
};

struct node *head;

int main (){
	int choice=0;
	printf("DYNAMIC STACK");
	while(1){
		printf("\n\nChose any of the following options:\n");
		printf("\n 0: Exit 1: Push 2: Pop 3: Peek\n 4: Check if stack is empty\n");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
			case 1: push(); break;
			case 2: pop(); break;
			case 3: peek(); break;
			case 4: isEmpty(); break;
			default: printf("Please choose a correct option!");
		}
	}
}

void push (){
	int val;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be pushed: ");
	scanf("%d", &val);

	if(head == NULL){
		ptr->val = val;
		ptr->next = NULL;
		head = ptr;
	}
	else{
		ptr->val = val;
		ptr->next = head;
		head=ptr;
	}
}

int pop(){
	int item;
	struct node *ptr;
	if (head == NULL)
		printf("Underflow State: can't remove any item");
	else{
		item = head->val;
		ptr = head;
		head = head->next;
		free(ptr);
		printf("%d is popped out of the stack", item);
		return item;
	}
	return -1;
}

int peek(){
	int x = head->val;
	printf("%d is the top most element of the stack\n", x);
	return x;
}

bool isEmpty(){
	if(head == NULL){
		printf("Stack is empty: Underflow State\n");
;        return true;
	}
	printf("Stack is not empty\n");
	return false;
}

*/

/*
// QUEUE 

#include <stdio.h>
# define SIZE 100
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
main()
{
	int ch;
	while (1)
	{
		printf("1.Enqueue Operation\n");
		printf("2.Dequeue Operation\n");
		printf("3.Display the Queue\n");
		printf("4.Exit\n");
		printf("Enter your choice of operations : ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
			enqueue();
			break;
			case 2:
			dequeue();
			break;
			case 3:
			show();
			break;
			case 4:
			exit(0);
			default:
			printf("Incorrect choice \n");
		}
	}
}

void enqueue()
{
	int insert_item;
	if (Rear == SIZE - 1)
	   printf("Overflow \n");
	else
	{
		if (Front == - 1)

		Front = 0;
		printf("Element to be inserted in the Queue\n : ");
		scanf("%d", &insert_item);
		Rear = Rear + 1;
		inp_arr[Rear] = insert_item;
	}
}

void dequeue()
{
	if (Front == - 1 || Front > Rear)
	{
		printf("Underflow \n");
		return ;
	}
	else
	{
		printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
		Front = Front + 1;
	}
}

void show()
{

	if (Front == - 1)
		printf("Empty Queue \n");
	else
	{
		printf("Queue: \n");
		for (int i = Front; i <= Rear; i++)
			printf("%d ", inp_arr[i]);
		printf("\n");
	}
}