#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node* next_node;
	short is_last;
	short is_empty;
};

void print_list(struct node* head){
	if (head -> is_last == 1){
		printf("Empty list");
		return ;
	}
	head = head -> next_node;
	while ((head -> is_last) != 1){
		printf("%d -> ", head -> value);
		head = head -> next_node;
	}
	printf("%d\n", head -> value);
}

void insert_node(struct node* head, int value, int index){
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node -> value = value;
	if (head -> is_last == 1){
		head -> is_last = 0;
		head -> next_node = new_node;
		new_node -> is_last = 1;
		return ;
	}
	int position = -1;
	struct node* last_node = head;
	while (position < index && (head -> is_last) != 1) {
		last_node = head;
		head = head -> next_node;
		position++;
	}
	
	if (position < index) {	
		new_node -> is_last = 1;
		head -> next_node = new_node;
		head -> is_last = 0;
	} else {
		new_node -> next_node = head;
		new_node -> is_last = 0;
		last_node -> next_node = new_node;
		last_node -> is_last = 0;
	}
}

void delete_node(struct node* head, int index){
	if (head -> is_last == 1){
		return ;
	}
	int position = -1;
	struct node* last_node = head;
	while (position < index && (head -> is_last) != 1) {
		last_node = head;
		head = head -> next_node;
		position++;
	}
	if (position < index) {	
		printf("INDEX ERROR");
		return ;
	}
	if (head -> is_last) {
		last_node -> is_last = 1;
	} else {
		last_node -> next_node = head -> next_node;
	}
	free(head);
}

void initialize_linked_list(struct node* head){
	head -> is_empty = 1;
	head -> is_last = 1;
}

	
int main(){
	struct node *linked_list = (struct node *) malloc(sizeof(struct node));
	initialize_linked_list(linked_list);
	insert_node(linked_list, 12, 0);
	insert_node(linked_list, 13, 1);
	insert_node(linked_list, 14, 2);
	insert_node(linked_list, 15, 3);
	print_list(linked_list);
	delete_node(linked_list, 0);
	delete_node(linked_list, 1);
	print_list(linked_list);
	return 0;
}