#include <stdio.h> 
#include <stdlib.h> 
#include "linked_list.h"
#include<string.h>



typedef struct linked_list linked_list;

int add_to_list(linked_list *ll, char *s);
int display_item(linked_list *ll);
int display_list(linked_list *ll);
linked_list * search_from_list(linked_list *ll, char *s);
int delete_from_list(linked_list *ll, int index);

int add_to_list(linked_list *ll, char *s){
	struct linked_list* new_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	struct linked_list* temp = ll;
	int i =0;
	new_list->next=NULL;
	if(ll == NULL){			
		ll=new_list;		/*If the Linked List is empty, then make the new node as head */
		return -1;
	}
	else{
		while(temp->next !=NULL){	/*till the last node */
		temp = temp->next;
		}
		temp->next = new_list;		/*old last node links to new node */
		new_list->data = s;
		new_list->index = temp->index+1;
		new_list->next = NULL;
		i = new_list->index;	
	}
	return i;
}


int display_item(linked_list *ll){
	if(ll==NULL) return -1;
	else{
		printf(" %d ", ll->index);
		printf(" %s ", ll->data);
		printf(" %p ", ll->next);
		return 0;
		}
}


int display_list(linked_list *ll){
	if(ll==NULL) return -1;
		else{
			while (ll != NULL) {
			printf(" %s ", ll->data); 
			ll = ll->next; 
			return 0;
			} 
		}
}

linked_list *search_from_list(linked_list *ll, char *s)
{
	linked_list *temp;
	int count=0;
	int cmp;
	while(ll != NULL)
	{
		cmp=strcmp(s,ll->data);
		if(cmp==0)
		{
			temp = ll;
			return temp;
		}
		ll=ll->next;
	}
}


int delete_from_list(linked_list *ll, int index){
	struct linked_list* temp = ll;
	struct linked_list* prev;
	int i=0;
	if(ll==NULL) return -1;
	else{
		while(temp != NULL){					
			if(temp->index == index){
				prev->next=temp->next;
				free(temp);			
				break;
			}
			else{
				prev=temp;				//save the previous node to *temp
				temp=temp->next;		//move to next node 
			}
		}
		
		
		struct linked_list* count = ll;
		while(count->next !=NULL){		//count the length of new list
		count = count->next;
		i++;
		}
		return i;
	}
}