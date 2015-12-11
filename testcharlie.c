#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "blocked_stack_int.h"
/*************************************************************/
struct node
{
	struct node *next; 			//points to next node in stack 
	int *element;				//creates a pointer to 
	int top;					//
	int s;
};
/*************************************************************/
struct stack_int_implementation
{
	struct node * top;
	int size;
	int block_size;
};
/*************************************************************/
stack_int * new_blocked_stack_int(int block_size){
	stack_int * s = (stack_int*)malloc(sizeof(block_size));	//allocates memory for the stack 
	s->top = NULL; 								//this makes it so the top of the stack holds no value on creation							
	s->size = block_size;							//sets the size of the stack to zero
	s->block_size = block_size;						//assigns block_size and the block size 
	return s;
};


/*************************************************************/
int stack_int_isempty(stack_int *s){
	assert(s!=NULL);								//checks that s is defined  
	return (s->size == 0); 							// this will returns true if the size is equal to zero
}

/*************************************************************/
int  stack_int_size(stack_int *s){
	assert(s!=NULL);								//checks that s is defined
	return (s->size);								//this will return how many items have been added to the stack
}

/*************************************************************/
void stack_int_push(stack_int *s, int x){
	assert(s!=NULL);								//checks that s is defined
	if (s->size == 0 || s->top->top >= (s->block_size)) {
		struct node *next = (struct node *)malloc(s->block_size * sizeof(int));
	}
	else{
		s->top->element[s->top->top] = x;				//this point to next available in the elements array
		(s->top->top)++;							//this pushs element top down and adds element to top
		(s->size)++;								//this adds 1 to the size of the stack 
	}	
}
/*************************************************************/
void stack_int_pop(stack_int *s){
	assert(s!=NULL);								//checks if s is defined 
	if(stack_int_isempty(s)){							//this calls the stack_int_empty function to see if the stack is empty 
		printf("No value can be popped as the stack is empty");// if it is empty a error message is provided as no element can be popped
		exit(1);
	}
	else{
		s->top->element[s->top->top]--;
		(s->size)--;
	}
}		
/************************************************************/
int  stack_int_top(stack_int *s){
	assert(s!=NULL);
	if(stack_int_isempty(s)){
		printf("stack is empty\n");
		exit(1);
	}
	else{ 
		return (s->top->element);
	}
}
/*************************************************************/
void stack_int_display(stack_int *s){
	assert(s!=NULL);								//checks that s is defined
	struct node *p = s->top;
	printf("Stack=/n -----");
	if (p!=NULL){
		while(p->next!=NULL){
		         printf("[");
			 printf("%i", p->element);
	                 printf("]/n");
                	 p = p->next;
		 }
		printf("%i", p->element);
	}
	printf("-----");
}
/*************************************************************/
void stack_int_release(stack_int *s){
	assert(s!=NULL);
	free(s);
}
