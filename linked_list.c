#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};
typedef struct node node_t;

//prototypes
void printlist(const node_t*);
node_t *create(int);
node_t *push(node_t *, node_t **);
node_t *find(node_t *, int);
node_t *unshift(node_t*,node_t*);
node_t *pop(node_t**);

int main(void){
	node_t *h = 0;
		
	for(int i =0; i<23 ; i++)
		push(create(i+1),&h);

	printlist(h);

}

void printlist(const node_t* header){
	for(const node_t *i = header; i; i=i->next)
		printf("value is %i\n",i->value);
}

node_t *create(int value){
	node_t *new = malloc(sizeof(node_t));
	new->value=value;
	//new->next=0;
	return new;
}

node_t *push(node_t *new, node_t **head){
	new->next = *head;
	*head=new;
	return new;
}

node_t *find(node_t *head, int value){
	for(node_t *i=head;i;i=i->next)
		if(i->value == value) return i;
	return 0;
}

node_t *unshift(node_t *new, node_t *current){
	new->next = current->next;
	current->next = new;
	return new;
}
node_t *pop(node_t **head){
	node_t *tmp = *head;
	*head = (*head)->next;
	return tmp;
}

