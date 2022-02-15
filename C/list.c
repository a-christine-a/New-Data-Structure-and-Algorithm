/*
##############################################################################
##                                                                          ##
##                        AUTHOR: JEFF ODHIAMBO                             ##
##                            DESCRIPTION                                   ##
##   This is a code that will be used in the implementation of operations   ##
##   that can be performed on array, singly linked list, queue and stack    ##
##                        DATE: FEB 15th, 2022                              ##
##                          VERSION: v1.0                                   ##
##              CONTACT: smarttech.allservices@gmail.com                    ##
##                                                                          ##
##############################################################################
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
	int data;
	struct Node *next;
};

void traverse();
void delete_begin();
void delete_at_point(int);
void delete_end();
void insert_begin(int);
void insert_at_point(int, int);
void insert_end(int);
void search(int);
void sort_asc();
void sort_dec();
bool isFull();
bool isEmpty();

int input();
//Global variables
struct Node *head = NULL;
struct Node *tail = NULL;
int size = 0;

void main(){
    char choose;
    int option,item,pos;
    home:
    //clear screen for UNIX OS
    system("clear");
    //clear screen for windows OS
    system("cls");
    //menu
    sub_menu();
    option = input();
    if(option == 1){
        printf("\n==================| Traverse Operations |====================\n");
        traverse();
    }
    else if(option == 2){
        printf("\n==================| Delete Operations |====================\n\n");
        printf("\t\t1. Delete 1st Element\n");
        printf("\t\t2. Delete Element at a point\n");
        printf("\t\t3. Delete last Element\n");
        option = input();
        if(option == 1){
            delete_begin();
        }
        else if(option == 2){
            printf("\n[+]Enter position >>> ");
            scanf("%d",&pos);
            delete_at_point(pos);
        }
        else if(option == 3){
            delete_end();
        }
        else{
            printf("Invalid Choice, try options 1 to 3");
        }
    }
    else if(option == 3){
        printf("\n==================| Insert Operations |====================\n\n");
        printf("\t\t1. Insert 1st Element\n");
        printf("\t\t2. Insert Element at a point\n");
        printf("\t\t3. Insert last Element\n");
        option = input();
        if(option == 1){
            printf("[+]Enter value to insert >>> ");
            scanf("%d",&item);
            insert_begin(item);
        }
        else if(option == 2){
            printf("[+]Enter value to insert >>> ");
            scanf("%d",&item);
            printf("\n[+]Enter position >>> ");
            scanf("%d",&pos);
            insert_at_point(item,pos);
        }
        else if(option == 3){
            printf("[+]Enter value to insert >>> ");
            scanf("%d",&item);
            insert_end(item);
        }
        else{
            printf("Invalid Choice, try options 1 to 3");
        }
    }
    else if(option == 4){
        printf("\n==================| Search Operation |====================\n");
        printf("[+] Enter element to search for >>> ");
        scanf("%d",&item);
        search(item);
    }
    else if(option == 5){
        printf("\n==================| Sort Operations |====================\n\n");
        printf("\t\t1. Sort in Ascending Order\n");
        printf("\t\t2. Sort in Descending order\n");
        option = input();
        if(option == 1){
            sort_asc();
        }
        else if(option == 2){
            sort_dec();
        }
        else{
            printf("\n\nInvalid Option!! Try with option 1 or 2!\n\n");
        }
    }
    else if(option == 6){
        printf("\n==================| isFull Operation |====================\n");
        isFull();
    }
    else if(option == 7){
        printf("\n==================| isEmpty Operation |====================\n");
        isEmpty();
    }
    else{
        printf("\n\nInvalid Options, Try a number between 1 and 7\n\n");
    }
    printf("\n--------------------[  --BY JEFF--  ]-----------------------\n\n");
    printf("\nWould you like to proceed, Enter 1 to proceed or any other key to cancel\n");
    option = input();
    if(option == 1){
        goto home;
    }
    else{
        return 0;
    }
}
int input(){
    int option;
    printf("[+]Select an option >>> ");
    scanf("%d",&option);
    return option;
}
void sub_menu(){
	printf("\n==================| List Operations |====================\n\n");
	printf("\t\t1. Traverse Entire Node\n");
	printf("\t\t2. Delete a Node\n");
	printf("\t\t3. Insert a Node\n");
	printf("\t\t4. Search a Node\n");
	printf("\t\t5. Sort Nodes in the List\n");
	printf("\t\t6. Check if List is Full\n");
	printf("\t\t7. Check if List is Empty\n");
	printf("--------------------[  --END--  ]-----------------------\n\n");
}
void traverse(){
    struct Node *tmp;
	if(isEmpty()==1){}
	else{
		int i = 0;
		tmp = head;
		printf("________________________________________________________\n");
		printf("Position \t\t Data \t\t NextNodeAddress\n");
		printf("________________________________________________________\n");
		printf("head \t\t\t %d \t\t %p\n", head -> data, head -> next);
		while(tmp -> next != NULL)
		{
			printf("%d \t\t\t %d \t\t %p\n",i, tmp -> data, tmp -> next);
			i ++;
			tmp = tmp -> next;
		}
		printf("________________________________________________________\n");
	}
}
void delete_begin(){
	struct Node *tmp;
	if(isEmpty()==1){return;}
	else if (head -> next == NULL){
		tmp = head;
		free(tmp);
		head = NULL;
	}
	else{
		tmp = head;
		head = tmp -> next;
		free(tmp);
	}
	printf("[*]Deleting first node of linked list...\n");
	printf("\n\t\tFirst Node Deleted Successfully!!\n\n");
}
void delete_at_point(int pos){
    struct Node *tmpl, *tmpl2;
	int i;
	if(isEmpty()==1){return;}
	else if (head -> next == NULL){
		if(pos == 0){
			tmpl = head;
			head = NULL;
			free(tmpl);
		}
		else{
			printf("[!]Coulnt Delete from Specified position.Not Enough Nodes\n");
			return;
		}
	}
	else{
		tmpl = head;
		for(i=0;i<=pos;i++){
			tmpl2 = tmpl;
			tmpl = tmpl -> next;
			if(tmpl2 == NULL){
				printf("[!]Couldnt Delete Item at position %d.Not Enough Items\n", pos);
				return;
			}
		}
		tmpl2 -> next = tmpl -> next;
		free(tmpl);
	}
	printf("[*]Deleting Node at position %d of the linked list...\n", pos);
	printf("\n\t\tNode at %d Successfully Deleted!!", pos);
}
void delete_end(){
    struct Node *tmplast, *tmplast2;
	printf("[*]Deleting Last node of linked list...\n");
	if(isEmpty()==1){return;}
	else if(head -> next == NULL){
		tmplast = head;
		free(tmplast);
		head = NULL;
	}
	else{
		int i;
		tmplast = head;
		while(tmplast -> next != NULL){
			tmplast2 = tmplast;		//2nd last node
			tmplast = tmplast -> next;		//last node
		}
		tmplast2 -> next = NULL;	//disconnect with the last node
		free(tmplast);		//delete the last node
		printf("[*]Last Node Successfully Deleted\n\n");
	}
}
void insert_begin(int data){
	//	create new node bellow
	struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
	if (newnode == NULL){
		perror("[!]An Error occured on Memmory allocation");
		exit(0);
	}
    printf("[*]Memmory of size %d is allocated at: %p\n",sizeof(struct Node), newnode);
	newnode -> data = data;
	newnode -> next = NULL;
	//if structure is empty
	if(isEmpty() == 1){head = newnode;}
	else{
		newnode -> next = head;
		head = newnode;
	}
	printf("\n[*]Inserting \"%d\" at the begining of linked list ...\n", data);
	printf("\n\t\tNode Successfully Inserted!!\n\n");
}
void insert_at_point(int data, int pos){
    struct Node *tmp;
	int i;
	printf("[*]Inserting \"%d\" at the \"%d\"'s' position of linked list\n", data, pos);
	//	create new node bellow
	struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
	if (newnode == NULL)
	{
		perror("\n\t\tAn Error Occured when allocating memmory!");
		exit(0);
	}
	newnode -> data = data;
	newnode -> next = NULL;
	if (isEmpty()==1){
		if (pos != 0){
			printf("\n\t\tCant insert at position %d\n", pos);
			return;
		}
		else{
			head = newnode;
		}
	}
	else{
		tmp = head;
		for(i=0;i <= pos;i++){
			tmp = tmp -> next;
			if (tmp == NULL){
				printf("\n\t\tCouldnt Insert!!\n");
				return;
			}
		}
		newnode -> next = tmp;
	}
	printf("\n\t\tNode Inserted Successfully!!\n\n");
}
void insert_end(int data){
    struct Node *tmp;
	printf("[*]Inserting \"%d\" at the end of linked list\n", data);
	//	create new node bellow
	struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));  //alocate mem and store addr in temp
	//	check for memmory allocation Error
	if (newnode == NULL)
	{
		perror("[!]An Error Occured when allocating memmory!");
		exit(0);
	}
	newnode -> data = data;
	newnode -> next = NULL;
	if (isEmpty()==1) {head = newnode;}
	else{
		tmp = head;
		while(tmp -> next != NULL)
		{
			tmp = tmp -> next;
		}
		tmp -> next = newnode;
	}
	printf("\n\t\tNode Successfully Inserted!\n\n");
}
void search(int data){
    struct Node *tmp;
	int i = 0;
	if(isEmpty()==1){}
	else{
        tmp = head;	//make tmp point to 1st Node
		//test for first data in the list with data provided
		if(tmp -> data == data){
			printf("Item %d Found At Position %d\n", data, i);
			return;	//teminate if found
		}
		else{
			i++;
			//loop through data in list
			while(tmp -> next != NULL){
				if(tmp -> data == data){
					printf("Item %d Found At Position %d\n", data, i);
					break;		//if found break out of loop;
				}
				tmp = tmp -> next;
			}
			if(tmp -> next == NULL){
				printf("\t\t[!]No Match Found !!\n");
			}
		}
	}
}
void sort_asc(){
    if(isEmpty()==1){return;}
    else{
        printf("\n\t\tSorting ... \n\t\tNot yet implemented\n");
    }
}
void sort_dec(){
    if(isEmpty()==1){return;}
    else{
        printf("\n\t\tSorting ... \n\t\tNot yet implemented\n");
    }
}
bool isFull(){
    if(isEmpty()==1){return;}
    else{
        printf("\n\t\tChecking ... \n\t\tNot yet implemented\n");
    }
}
bool isEmpty(){
    if(head == NULL){
		printf("\n\n\t\tThe Linked List is Empty\n\n");
		return 1;
    }
	else
        printf("\n\t\tThe List is not Empty\n");
        return 0;
}
